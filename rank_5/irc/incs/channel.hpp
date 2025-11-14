
#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include "server.hpp"

class Server;

class Channel
{
	private:
		std::string _name;
		std::string _topic;
		std::string _password;
		std::string _mode;
		std::vector<int> _users;
		std::vector<int> _operators;
		std::vector<int> _invites;
		size_t _user_limits;
		bool _limit_user_on;
		bool _private;
		bool _invite_only;
		bool _password_only;
		bool _topic_only;
	public:
		Channel();
		Channel(std::string name, int owner_fd);
		~Channel();
		bool isPasswordOnly();
		bool checkOperator(int fd);
		std::string getName();
		std::string getTopic();
		std::string getPassword();
		std::string getMode();
		std::vector<int> getUsers();
		std::vector<int> getInvites();
		std::vector<int> getOperators();
		size_t getUserLimits();
		bool isLimitUserOn();
		bool isPrivate();
		bool isInviteOnly();
		bool isTopicOnly();
		void removeUser(int fd);
		void setName(std::string name);
		void setTopic(std::string topic);
		void setPassword(std::string password);
		void setMode(std::string mode);
		void setUsers(std::vector<int> users);
		void setOperators(std::vector<int> operators);
		void addUserToOperators(int fd);
		void setUserLimits(size_t user_limits);
		void setLimitUserOn(bool limit_user_on);
		void setInviteOnly(bool invite_only);
		void setPasswordOnly(bool password_only);
		void setTopicOnly(bool topic_only);
		void addUser(int fd);
		void sendToAllInChannel(Server &server, std::string message);
		void broadcastMessage(Client *client, std::string message, Server &server);
		void removeOperator(int fd);
		bool isUserInChannel(int fd);
		bool isUserInvited(int fd);
		void addInvite(int fd);
		void removeInvite(int fd);
		// void printOperators();

};

#endif