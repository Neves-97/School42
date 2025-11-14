#pragma once

#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <algorithm>
#include <vector>
#include <map>
#include <netdb.h>
#include <cstdio> 
#include <cstring>
#include <cerrno>
#include <csignal>
#include <poll.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include "client.hpp"
#include "channel.hpp"

class Channel;

#define MAX_CONNECTIONS 10


class Server {
public:
	Server(const char *port, const char *password);
	~Server();
	void start();
	void on_client_connect(int fd);
	void on_client_disconnect(int fd);
	void broadcast_message(int sender_fd, const std::string &message);
	void handle_command(int client_fd, const std::string &message);
	bool exec_command(int client_fd, const std::string &message);
	bool validNickname(const std::string &nickname) const;
	bool validUsername(const std::string &username) const;
	bool checkChannelName(std::string channel_name);
	void addChannel(Channel *channel);
	std::string get_password();
	void setPassword(const std::string &password);
	Client* find_client_by_fd(int client_fd);
	std::vector<Channel *> getChannels();
	std::vector<Channel *> searchChannel(std::string channel_name);
	std::vector<Client *> getClients();
	std::vector<Client *> searchClient(std::string client_name);
	Client* searchClientByNick(std::string nickname);
	Channel* getChannelByName(std::string &channel_name);
	void	sendToAllClients(int sender_fd, const std::string &message);
	void	sendToAllClientsInChannel(int sender_fd, const std::string &message, const std::string &channel_name);
	void	process_client_message(Client *client);
private:
	int _server_fd;
	int _epoll_fd;
	std::vector<Client *> _clients;
	std::vector<Channel *> _channels;
	std::string _password;
	std::map<int, std::string> client_buffers;
	struct sockaddr_in _addr;
};

#endif