#include "../incs/server.hpp"
#include "../incs/validation.hpp"
#include "../incs/client.hpp"
#include "../incs/channel.hpp"
#include "../incs/commands.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cerrno>
#include <csignal>
#include <poll.h>
#include <map>
#include <vector>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/epoll.h>
#include <fcntl.h>

bool run = true;

// if crtl+c turns false exit

void signal_handler(int sig) {
	(void)sig;
	run = false;
}

Server::Server(const char *port, const char *password) {
	_password = password;
	_server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (_server_fd < 0) {
		std::cerr << "Socket creation failed" << std::endl;
		exit(1);
	}
	
	memset(&_addr, 0, sizeof(_addr));
	_addr.sin_family = AF_INET;
	_addr.sin_addr.s_addr = INADDR_ANY;
	_addr.sin_port = htons(atoi(port));
	
	int optval = 1;
	setsockopt(_server_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
	
	if (bind(_server_fd, (struct sockaddr*)&_addr, sizeof(_addr)) < 0) {
		std::cerr << "Binding failed" << std::endl;
		exit(1);
	}
	
	if (listen(_server_fd, 10) < 0) {
		std::cerr << "Listening failed" << std::endl;
		exit(1);
	}

	// Create epoll instance
	_epoll_fd = epoll_create1(0);
	if (_epoll_fd == -1) {
		std::cerr << "Epoll creation failed" << std::endl;
		exit(1);
	}

	// Add server socket to epoll instance
	struct epoll_event event;
	event.events = EPOLLIN;
	event.data.fd = _server_fd;
	if (epoll_ctl(_epoll_fd, EPOLL_CTL_ADD, _server_fd, &event) == -1) {
		std::cerr << "Epoll control failed" << std::endl;
		exit(1);
	}
}

Server::~Server()
{
}

void Server::start() {
	struct epoll_event events[MAX_CONNECTIONS];

	signal(SIGINT, signal_handler);

	while (run) {
		int nfds = epoll_wait(_epoll_fd, events, MAX_CONNECTIONS, -1);
		if (nfds == -1) {
			if (errno == EINTR) continue;
			std::cerr << "Epoll wait error" << std::endl;
			break;
		}

		for (int i = 0; i < nfds; ++i) {
			if (events[i].data.fd == _server_fd) {
				struct sockaddr_in addr;
				socklen_t addr_len = sizeof(addr);
				int client_fd = accept(_server_fd, (struct sockaddr*)&addr, &addr_len);
				if (client_fd < 0) {
					perror("accept failed");
					continue;
				}

				struct epoll_event event;
				event.events = EPOLLIN;
				event.data.fd = client_fd;
				if (epoll_ctl(_epoll_fd, EPOLL_CTL_ADD, client_fd, &event) == -1) {
					std::cerr << "Epoll control failed" << std::endl;
					close(client_fd);
					continue;
				}

				// Create new client and add to the list
				Client* new_client = new Client();
				new_client->set_fd(client_fd);
				new_client->set_ip(inet_ntoa(addr.sin_addr));
				new_client->set_port(ntohs(addr.sin_port));
				_clients.push_back(new_client);
				std::cout << "New client connected: " << client_fd << std::endl;
			} else {
				char buffer[1024];
				memset(buffer, 0, sizeof(buffer));
				int bytes_read = recv(events[i].data.fd, buffer, sizeof(buffer) - 1, 0);

				if (bytes_read > 0) {
					buffer[bytes_read] = '\0';
					std::string message(buffer);

					client_buffers[events[i].data.fd] += message;
					size_t pos;
					while ((pos = client_buffers[events[i].data.fd].find("\n")) != std::string::npos) {
						std::string complete_message = client_buffers[events[i].data.fd].substr(0, pos);
						client_buffers[events[i].data.fd].erase(0, pos + 1);
				
						// Remover '\r' se existir no final da mensagem
						if (!complete_message.empty() && complete_message[complete_message.size() - 1] == '\r') {
							complete_message.erase(complete_message.size() - 1);
						}
				
						std::cout << "Received message: " << complete_message << std::endl;
						handle_command(events[i].data.fd, complete_message);
					}
				} else {
					on_client_disconnect(events[i].data.fd);
					close(events[i].data.fd);
					epoll_ctl(_epoll_fd, EPOLL_CTL_DEL, events[i].data.fd, NULL);
				}
			}
		}
	}
	close(_server_fd);
	close(_epoll_fd);

	for (size_t i = 0; i < _channels.size(); ++i) {
		delete _channels[i];
	}
	for (size_t i = 0; i < _clients.size(); ++i) {
		delete _clients[i];
	}
	_clients.clear();	
	std::cout << "Server shutting down..." << std::endl;
}

Client*	Server::find_client_by_fd(int client_fd) {
	for (size_t i = 0; i < _clients.size(); ++i)
		if (_clients[i]->get_fd() == client_fd)
			return _clients[i];
	return NULL;
}

bool Server::exec_command(int client_fd, const std::string &message) {
	std::istringstream iss(message);
	std::string command;
	Command cmd;
	iss >> command;

	std::cout << "Command: " << command << std::endl;
	Client* client = find_client_by_fd(client_fd);
	if (!client) {
		std::string response = "Client not found\n";
		send(client_fd, response.c_str(), response.length(), 0);
		return false;
	}
	if (client->get_authenticated() == false && (command != "PASS" && command != "NICK" && command != "USER" && command != "QUIT")) {
		std::string response = "You must authenticate first\n";
		send(client_fd, response.c_str(), response.length(), 0);
		return false;
	}
	
	if (command == "PASS") {
		std::string password;
		iss >> password;
		cmd.password(*this, *client, password);
	} else if (command == "QUIT") {
		std::string response = "Goodbye!";
		send(client_fd, response.c_str(), response.length(), 0);
		on_client_disconnect(client_fd);
		close(client_fd);
	} else if (command == "NICK") {
		std::string nickname;
		iss >> nickname;
		cmd.nickname(*this, _clients, *client, nickname);
	} else if (command == "USER") {
		std::string username;
		iss >> username;
		cmd.username(*this, _clients, *client, username);
	} else if (command == "JOIN") {
		cmd.join_cmd(client, message, *this);
	} else if (command == "PRIVMSG") {
		std::string target;
		std::string msg;
		iss >> target;
		std::getline(iss, msg);
		cmd.privmsg(client, target, msg, *this);
	} else if (command == "KICK") {
		cmd.kick(client, message, *this);
	} else if (command == "INVITE") {
		cmd.invite(*this, client, message);
	} else if (command == "TOPIC") {
		cmd.Topic(*this, client, message);
	} else if (command == "MODE") {
		cmd.mode(client, message, *this);
	} else if (command == "WHO") {
		cmd.who(*this, client, message);
	} else if (command == "PART") {
		cmd.part(*this, client, message);
	} else {
		std::string response = "Unknown command: " + command + "\n";
		send(client_fd, response.c_str(), response.length(), 0);
		return false;
	}
	return true;
}

void Server::handle_command(int client_fd, const std::string &message) {
		if (exec_command(client_fd, message) == false) // Not sure if this is the right way to handle
			return;
		// else 
		// 	broadcast_message(client_fd, message);
}


void Server::process_client_message(Client *client) {
	char buffer[1024];
	int bytesRead = recv(client->get_fd(), buffer, sizeof(buffer), 0);
	
	if (bytesRead <= 0) {
		std::cerr << "Error or no data received from client" << std::endl;
		return;
	}

	std::string message(buffer, bytesRead);

	// Verificar se a mensagem é um comando NICK
	if (message.find("NICK") == 0) {
		std::string nickname = message.substr(5, message.find("\r\n") - 5);
		nickname.erase(std::remove(nickname.begin(), nickname.end(), ' '), nickname.end()); 
		nickname.erase(std::remove(nickname.begin(), nickname.end(), '\r'), nickname.end());
		nickname.erase(std::remove(nickname.begin(), nickname.end(), '\n'), nickname.end());
		
		client->set_nickname(nickname);

		std::string welcomeMessage = ":localhost 001 " + nickname + " :Welcome to the IRC Network, " + nickname + "!" + client->get_name() + "@localhost\r\n";
		client->send_message(welcomeMessage);

		std::cout << "Client " << nickname << " connected and nickname set." << std::endl;
	} else {
		std::cerr << "Expected NICK command, but got: " << message << std::endl;
	}
}

void Server::on_client_connect(int fd) {
	struct sockaddr_in client_addr;
	// struct epoll_event client_event;
	socklen_t addr_len = sizeof(client_addr);

	int newClientSocket = accept(fd, (struct sockaddr*)&client_addr, &addr_len);
	if (newClientSocket == -1) {
		std::cerr << "Accept failed" << std::endl;
		return;
	}
	if (fcntl(newClientSocket, F_SETFL, O_NONBLOCK) == -1) {
		std::cerr << "Failed to set non-blocking" << std::endl;
		close(newClientSocket);
		return;
	}
	Client* new_client = new Client();
	new_client->set_fd(newClientSocket);
	new_client->set_ip(inet_ntoa(client_addr.sin_addr));
	new_client->set_port(ntohs(client_addr.sin_port));
	_clients.push_back(new_client);

	std::cout << "New client connected: " << newClientSocket << std::endl;

	process_client_message(new_client);
}

void Server::on_client_disconnect(int fd) {
	Client *client = find_client_by_fd(fd);
	if (!client)
		return;
	for (size_t i = 0; i < _clients.size(); i++) {
		if (_clients[i]->get_fd() == fd) {
			std::cout << "Client <" << fd << "> Disconnected" << std::endl;
			delete _clients[i];
			_clients.erase(_clients.begin() + i);
			break;
		}
	}
	epoll_ctl(_epoll_fd, EPOLL_CTL_DEL, fd, NULL);
	close(fd);
}

void Server::broadcast_message(int sender_fd, const std::string &message) {
	for (size_t i = 0; i < _clients.size(); i++) {
		if (_clients[i]->get_fd() != sender_fd) {
			send(_clients[i]->get_fd(), message.c_str(), message.length(), 0);
		}
	}
}

bool Server::checkChannelName(std::string channel_name)
{
	for(std::vector<Channel *>::iterator it = _channels.begin(); it != _channels.end(); ++it)
	{
		if ((*it)->getName() == channel_name)
			return true;
	}
	return false;
}

std::vector<Channel *> Server::getChannels()
{
	return _channels;
}

Client* Server::searchClientByNick(std::string nickname)
{
	for(std::vector<Client *>::iterator it = _clients.begin(); it != _clients.end(); ++it)
	{
		if ((*it)->get_nickname() == nickname)
			return *it;
	}
	return NULL;
}

Channel* Server::getChannelByName(std::string &channel_name)
{
	for(std::vector<Channel *>::iterator it = _channels.begin(); it != _channels.end(); ++it)
	{
		if ((*it)->getName() == channel_name)
			return *it;
	}
	return NULL;
}

void	Server::sendToAllClients(int sender_fd, const std::string &message)
{
	for (std::vector<Client *>::iterator it = _clients.begin(); it != _clients.end(); ++it)
	{
		if ((*it)->get_fd() != sender_fd)
			send((*it)->get_fd(), message.c_str(), message.length(), 0);
	}
}

void Server::sendToAllClientsInChannel(int sender_fd, const std::string &message, const std::string &channel_name) {
	for (std::vector<Client *>::iterator it = _clients.begin(); it != _clients.end(); ++it) {
		if ((*it)->get_fd() != sender_fd && (*it)->checkInChannel(channel_name, (*it)->getChannels())) {
			send((*it)->get_fd(), message.c_str(), message.length(), 0);
		}
	}
}


void Server::addChannel(Channel *channel)
{
	_channels.push_back(channel);
}

std::vector<Client *> Server::getClients()
{
	return _clients;
}

std::string Server::get_password()
{
	return _password;
}

void Server::setPassword(const std::string &password)
{
	_password = password;
}