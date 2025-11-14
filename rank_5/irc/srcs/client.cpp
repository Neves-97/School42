/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:05:05 by micarrel          #+#    #+#             */
/*   Updated: 2025/02/23 21:05:05 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.hpp"

Client::Client() {
	_connected = false;
	authenticated = false;
	_name = "";
	_nickname = "";
	_message = "";
	_host = "";
	_ip = "";
	_port = 0;
	_sockfd = 0;
	memset(&_server_addr, 0, sizeof(_server_addr));
	memset(_buffer, 0, sizeof(_buffer));
}

Client::Client(const char *ip, const char *port) {
	_ip = ip;
	_port = atoi(port);
	_connected = false;
	connect_to_server(ip, port);
}

Client::~Client()
{
	if (_connected) {
		close(_sockfd);
	}
}

void Client::start() // not sure if this is needed
{
	while (_connected) {
		std::string message;
		std::getline(std::cin, message);
		send_message(message);
		receive_message();
	}
}

void Client::connect_to_server(const char *ip, const char *port) {
	// Create socket for client
	_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (_sockfd < 0) {
		std::cerr << "Socket creation failed" << std::endl;
		exit(1);
	}

	// Create server address
	struct sockaddr_in server_addr;
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(atoi(port));
	if (inet_pton(AF_INET, ip, &server_addr.sin_addr) <= 0) {
		std::cerr << "Invalid address/ Address not supported" << std::endl;
		exit(1);
	}

	// Try to connect to server
	if (connect(_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
		std::cerr << "Connection failed" << std::endl;
		exit(1);
	}

	// Connection successful
	_connected = true;
	std::cout << "Connected to server at " << ip << ":" << port << std::endl;
}


void Client::send_message(const std::string &message) {
	if (send(_sockfd, message.c_str(), message.length(), 0) < 0) {
		std::cerr << "Send failed" << std::endl;
	}
}

void Client::receive_message() {
	memset(_buffer, 0, sizeof(_buffer));
	int bytes_received = recv(_sockfd, _buffer, sizeof(_buffer) - 1, 0);
	if (bytes_received < 0) {
		std::cerr << "Receive failed" << std::endl;
	} else if (bytes_received == 0) {
		std::cout << "Server disconnected" << std::endl;
		_connected = false;
	} else { // Message received
		std::cout << "Server: " << _buffer << std::endl;
	}
}

bool Client::checkInChannel(std::string channel_name, std::vector<std::string> channels)
{
    for (std::vector<std::string>::iterator it = channels.begin(); it != channels.end(); ++it)
    {
        if ((*it) == channel_name)
            return true;
    }
    return false;
}

void	Client::addChannel(std::string channel_name)
{
	_channels.push_back(channel_name);
}

void	Client::printChannels()
{
	for (std::vector<std::string>::iterator it = _channels.begin(); it != _channels.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
}

void	Client::removeChannel(std::string channel_name)
{
	for (std::vector<std::string>::iterator it = _channels.begin(); it != _channels.end(); ++it)
	{
		if ((*it) == channel_name)
		{
			_channels.erase(it);
			break;
		}
	}
}

std::vector<std::string> Client::getChannels() {
	return _channels;
}

void Client::set_name(const std::string &name) {
	_name = name;
}

void Client::set_nickname(const std::string &nickname) {
	_nickname = nickname;
}

void Client::set_message(const std::string &message) {
	_message = message;
}

void Client::set_host(const std::string &host) {
	_host = host;
}

void Client::set_authenticated(bool auth) {
	authenticated = auth;
}

void Client::set_fd(int fd) {
	_sockfd = fd;
}

std::string Client::get_name() {
	return _name;
}

std::string Client::get_nickname() {
	return _nickname;
}

std::string Client::get_message() {
	return _message;
}

std::string Client::get_host() {
	return _host;
}

bool Client::get_authenticated() {
	return authenticated;
}

void Client::set_ip(const std::string &ip) {
	_ip = ip;
}

void Client::set_port(int port) {
	_port = port;
}

int Client::get_fd() {
	return _sockfd;
}