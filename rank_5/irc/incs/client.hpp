#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <vector>
#include <map>
#include <netdb.h>
#include <cstdio> 
#include <cstring>
#include <cerrno>
#include <csignal>
#include <poll.h>
#include <sys/types.h>

class Client {
	private:
		struct sockaddr_in _server_addr;
		int _sockfd;
		int _fd;
		int _port;
		std::string _ip;
		std::string _client_ip;
		std::string _name;
		std::string _nickname;
		std::string _message;
		std::string _host;
		bool _connected;
		bool authenticated;
		char _buffer[1024];
		std::vector<std::string> _channels;
	public:
		Client();
		~Client();
		Client(const char *ip, const char *port);
		void start();
		void on_server_disconnect();
		void handle_command(const std::string &message);
		bool exec_command(const std::string &message);
		void send_message(const std::string &message);
		void receive_message();
		void set_name(const std::string &name);
		void set_nickname(const std::string &nickname);
		void set_message(const std::string &message);
		void set_host(const std::string &host);
		void set_authenticated(bool auth);
		void set_fd(int fd);
		void set_ip(const std::string &ip);
		void set_port(int port);
		void connect_to_server(const char *ip, const char *port);
		std::string get_name();
		std::string get_nickname();
		std::string get_message();
		std::string get_host();
		std::vector<std::string> getChannels();
		bool get_authenticated();
		int get_fd();
		void addChannel(std::string channel_name);
		void removeChannel(std::string channel_name);
		bool checkInChannel(std::string channel_name, std::vector<std::string> channels);
		void printChannels();
};

#endif