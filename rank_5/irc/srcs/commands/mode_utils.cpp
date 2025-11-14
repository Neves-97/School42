#include "../../incs/server.hpp"
#include "../../incs/channel.hpp"
#include "../../incs/commands.hpp"
#include "../../incs/client.hpp"

void Command::plus_o(Client *client, const std::string &message, Server &server) {
	std::string channel_name;
	std::string nickname;
	std::string hold;
	std::string mode;
	std::istringstream iss(message);
	iss >> hold;
	iss >> channel_name;
	iss >> mode;
	iss >> nickname;

	if (channel_name.empty()) {
		std::string response = ":server 461 " + client->get_nickname() + " MODE :Not enough parameters\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (!server.checkChannelName(channel_name)) {
		std::string response = ":server 403 " + client->get_nickname() + " " + channel_name + " :No such channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (nickname.empty()) {
		std::string response = ":server 461 " + client->get_nickname() + " MODE :Not enough parameters\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (!server.validNickname(nickname)) {
		std::string response = ":server 401 " + client->get_nickname() + " " + nickname + " :No such nick/channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (!client->checkInChannel(channel_name, client->getChannels())) {
		std::string response = ":server 442 " + client->get_nickname() + " " + channel_name + " :You're not on that channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	Client *user = server.searchClientByNick(nickname);
	if (!user->checkInChannel(channel_name, user->getChannels())) {
		std::string response = ":server 441 " + client->get_nickname() + " " + nickname + " " + channel_name + " :They aren't on that channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	Channel *channel = server.getChannelByName(channel_name);
	if (channel->checkOperator(user->get_fd())) {
		std::string response = ":server 443 " + client->get_nickname() + " " + nickname + " " + channel_name + " :is already an operator\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	channel->addUserToOperators(user->get_fd());
	std::string response = ":" + client->get_nickname() + " MODE " + channel_name + " +o " + nickname + "\r\n";
	channel->sendToAllInChannel(server, response);
}

void Command::minus_o(Client *client, const std::string &message, Server &server) {
	std::string channel_name;
	std::string nickname;
	std::string hold;
	std::string mode;
	std::istringstream iss(message);
	iss >> hold;
	iss >> channel_name;
	iss >> mode;
	iss >> nickname;

	if (channel_name.empty()) {
		std::string response = ":server 461 " + client->get_nickname() + " MODE :Not enough parameters\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (!server.checkChannelName(channel_name)) {
		std::string response = ":server 403 " + client->get_nickname() + " " + channel_name + " :No such channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (nickname.empty()) {
		std::string response = ":server 461 " + client->get_nickname() + " MODE :Not enough parameters\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (!server.validNickname(nickname)) {
		std::string response = ":server 401 " + client->get_nickname() + " " + nickname + " :No such nick/channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (!client->checkInChannel(channel_name, client->getChannels())) {
		std::string response = ":server 442 " + client->get_nickname() + " " + channel_name + " :You're not on that channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	Client *user = server.searchClientByNick(nickname);
	if (!user->checkInChannel(channel_name, user->getChannels())) {
		std::string response = ":server 441 " + client->get_nickname() + " " + nickname + " " + channel_name + " :They aren't on that channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	Channel *channel = server.getChannelByName(channel_name);
	if (!channel->checkOperator(user->get_fd())) {
		std::string response = ":server 482 " + client->get_nickname() + " " + channel_name + " :You're not channel operator\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	channel->removeOperator(user->get_fd());
	std::string response = ":" + client->get_nickname() + " MODE " + channel_name + " -o " + nickname + "\r\n";
	channel->sendToAllInChannel(server, response);
}

void Command::plus_i(Client *client, const std::string &message, Server &server) {
	std::string channel_name;
	std::string hold;
	std::string mode;
	std::istringstream iss(message);
	iss >> hold;
	iss >> channel_name;
	iss >> mode;

	if (channel_name.empty()) {
		std::string response = ":server 461 " + client->get_nickname() + " MODE :Not enough parameters\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (!server.checkChannelName(channel_name)) {
		std::string response = ":server 403 " + client->get_nickname() + " " + channel_name + " :No such channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (!client->checkInChannel(channel_name, client->getChannels())) {
		std::string response = ":server 442 " + client->get_nickname() + " " + channel_name + " :You're not on that channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	Channel *channel = server.getChannelByName(channel_name);
	if (channel->isInviteOnly()) {
		std::string response = ":server 443 " + client->get_nickname() + " " + channel_name + " :Channel is already invite-only\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	channel->setInviteOnly(true);
	std::string response = ":" + client->get_nickname() + " MODE " + channel_name + " +i\r\n";
	channel->sendToAllInChannel(server, response);
}

void Command::minus_i(Client *client, const std::string &message, Server &server) {
	std::string channel_name;
	std::string hold;
	std::string mode;
	std::istringstream iss(message);
	iss >> hold;
	iss >> channel_name;
	iss >> mode;

	if (channel_name.empty()) {
		std::string response = ":server 461 " + client->get_nickname() + " MODE :Not enough parameters\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (!server.checkChannelName(channel_name)) {
		std::string response = ":server 403 " + client->get_nickname() + " " + channel_name + " :No such channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (!client->checkInChannel(channel_name, client->getChannels())) {
		std::string response = ":server 442 " + client->get_nickname() + " " + channel_name + " :You're not on that channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	Channel *channel = server.getChannelByName(channel_name);
	if (!channel->isInviteOnly()) {
		std::string response = ":server 443 " + client->get_nickname() + " " + channel_name + " :Channel is not invite-only\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	channel->setInviteOnly(false);
	std::string response = ":" + client->get_nickname() + " MODE " + channel_name + " -i\r\n";
	channel->sendToAllInChannel(server, response);
}

void Command::plus_t(Client *client, const std::string &message, Server &server) {
	std::string channel_name;
	std::string hold;
	std::string mode;
	std::istringstream iss(message);
	iss >> hold;
	iss >> channel_name;
	iss >> mode;

	if (channel_name.empty()) {
		std::string response = ":server 461 " + client->get_nickname() + " MODE :Not enough parameters\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (!server.checkChannelName(channel_name)) {
		std::string response = ":server 403 " + client->get_nickname() + " " + channel_name + " :No such channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (!client->checkInChannel(channel_name, client->getChannels())) {
		std::string response = ":server 442 " + client->get_nickname() + " " + channel_name + " :You're not on that channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	Channel *channel = server.getChannelByName(channel_name);
	if (channel->isTopicOnly()) {
		std::string response = ":server 443 " + client->get_nickname() + " " + channel_name + " :Channel is already topic-protected\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	channel->setTopicOnly(true);
	std::string response = ":" + client->get_nickname() + " MODE " + channel_name + " +t\r\n";
	channel->sendToAllInChannel(server, response);
}

void Command::minus_t(Client *client, const std::string &message, Server &server) {
	std::string channel_name;
	std::string hold;
	std::string mode;
	std::istringstream iss(message);
	iss >> hold;
	iss >> channel_name;
	iss >> mode;

	if (channel_name.empty()) {
		std::string response = ":server 461 " + client->get_nickname() + " MODE :Not enough parameters\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (!server.checkChannelName(channel_name)) {
		std::string response = ":server 403 " + client->get_nickname() + " " + channel_name + " :No such channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (!client->checkInChannel(channel_name, client->getChannels())) {
		std::string response = ":server 442 " + client->get_nickname() + " " + channel_name + " :You're not on that channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	Channel *channel = server.getChannelByName(channel_name);
	if (!channel->isTopicOnly()) {
		std::string response = ":server 443 " + client->get_nickname() + " " + channel_name + " :Channel is not topic-protected\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	channel->setTopicOnly(false);
	std::string response = ":" + client->get_nickname() + " MODE " + channel_name + " -t\r\n";
	channel->sendToAllInChannel(server, response);
}

void Command::plus_k(Client *client, const std::string &message, Server &server) {
	std::string channel_name;
	std::string password;
	std::string hold;
	std::string mode;
	std::istringstream iss(message);
	iss >> hold;
	iss >> channel_name;
	iss >> mode;
	iss >> password;

	if (channel_name.empty()) {
		std::string response = ":server 461 " + client->get_nickname() + " MODE :Not enough parameters\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (!server.checkChannelName(channel_name)) {
		std::string response = ":server 403 " + client->get_nickname() + " " + channel_name + " :No such channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (password.empty()) {
		std::string response = ":server 461 " + client->get_nickname() + " MODE :Not enough parameters\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (!client->checkInChannel(channel_name, client->getChannels())) {
		std::string response = ":server 442 " + client->get_nickname() + " " + channel_name + " :You're not on that channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	Channel *channel = server.getChannelByName(channel_name);
	channel->setPassword(password);
	std::string response = ":" + client->get_nickname() + " MODE " + channel_name + " +k " + password + "\r\n";
	channel->sendToAllInChannel(server, response);
}

void Command::minus_k(Client *client, const std::string &message, Server &server) {
	std::string channel_name;
	std::string hold;
	std::string mode;
	std::istringstream iss(message);
	iss >> hold;
	iss >> channel_name;
	iss >> mode;

	if (channel_name.empty()) {
		std::string response = ":server 461 " + client->get_nickname() + " MODE :Not enough parameters\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (!server.checkChannelName(channel_name)) {
		std::string response = ":server 403 " + client->get_nickname() + " " + channel_name + " :No such channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}	
	if (!client->checkInChannel(channel_name, client->getChannels())) {
		std::string response = ":server 442 " + client->get_nickname() + " " + channel_name + " :You're not on that channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	Channel *channel = server.getChannelByName(channel_name);
	if (channel->getPassword().empty()) {
		std::string response = ":server 472 " + client->get_nickname() + " k :Channel is not password protected\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	channel->setPassword("");
	std::string response = ":" + client->get_nickname() + " MODE " + channel_name + " -k\r\n";
	channel->sendToAllInChannel(server, response);
}

void Command::plus_l(Client *client, const std::string &message, Server &server) {
	std::string channel_name;
	std::string limit_number;
	std::string hold;
	std::istringstream iss(message);
	iss >> hold;
	iss >> channel_name;
	iss >> limit_number;

	if (channel_name.empty()) {
		std::string response = ":server 461 " + client->get_nickname() + " MODE :Not enough parameters\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (!server.checkChannelName(channel_name)) {
		std::string response = ":server 403 " + client->get_nickname() + " " + channel_name + " :No such channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (limit_number.empty()) {
		std::string response = ":server 461 " + client->get_nickname() + " MODE :Not enough parameters\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (!client->checkInChannel(channel_name, client->getChannels())) {
		std::string response = ":server 442 " + client->get_nickname() + " " + channel_name + " :You're not on that channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}

	Channel *channel = server.getChannelByName(channel_name);
	int limit;
	std::istringstream limit_stream(limit_number);
	if (!(limit_stream >> limit)) {
		std::string response = ":server 461 " + client->get_nickname() + " MODE :Invalid limit number\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}

	channel->setLimitUserOn(true);
	channel->setUserLimits(limit);

	std::string response = ":" + client->get_nickname() + " MODE " + channel_name + " +l " + limit_number + "\r\n";
	channel->sendToAllInChannel(server, response);
}

void Command::minus_l(Client *client, const std::string &message, Server &server) {
	std::string channel_name;
	std::string hold;
	std::istringstream iss(message);
	iss >> hold;
	iss >> channel_name;

	if (channel_name.empty()) {
		std::string response = ":server 461 " + client->get_nickname() + " MODE :Not enough parameters\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (!server.checkChannelName(channel_name)) {
		std::string response = ":server 403 " + client->get_nickname() + " " + channel_name + " :No such channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (!client->checkInChannel(channel_name, client->getChannels())) {
		std::string response = ":server 442 " + client->get_nickname() + " " + channel_name + " :You're not on that channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}

	Channel *channel = server.getChannelByName(channel_name);
	if (!channel->isLimitUserOn()) {
		std::string response = ":server 472 " + client->get_nickname() + " l :Channel is not limited\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}

	channel->setLimitUserOn(false);
	channel->setUserLimits(0);

	std::string response = ":" + client->get_nickname() + " MODE " + channel_name + " -l\r\n";
	channel->sendToAllInChannel(server, response);
}