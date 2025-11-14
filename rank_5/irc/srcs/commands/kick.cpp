
#include "../../incs/server.hpp"
#include "../../incs/channel.hpp"
#include "../../incs/commands.hpp"
#include "../../incs/client.hpp"

void Command::kick(Client *client, const std::string &msg, Server &server) {
	std::string channelName;
	std::string nickname;
	std::string reason;
	std::istringstream iss(msg);
	std::string command;

	iss >> command;
	iss >> channelName;
	iss >> nickname;
	std::getline(iss, reason);
	if (!reason.empty() && reason[0] == ' ')
		reason = reason.substr(1);

	if (channelName.empty() || nickname.empty()) {
		std::string response = ":server 461 " + client->get_nickname() + " KICK :Not enough parameters\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (!server.checkChannelName(channelName)) {
		std::string response = ":server 403 " + client->get_nickname() + " " + channelName + " :No such channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (!client->checkInChannel(channelName, client->getChannels())) {
		std::string response = ":server 442 " + client->get_nickname() + " " + channelName + " :You're not on that channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	Channel *channel = server.getChannelByName(channelName);
	if (!channel->checkOperator(client->get_fd())) {
		std::string response = ":server 482 " + client->get_nickname() + " " + channelName + " :You're not channel operator\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	Client *kicked = server.searchClientByNick(nickname);
	if (!kicked) {
		std::string response = ":server 401 " + client->get_nickname() + " " + nickname + " :No such nick/channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (!kicked->checkInChannel(channelName, kicked->getChannels())) {
		std::string response = ":server 441 " + client->get_nickname() + " " + nickname + " " + channelName + " :They aren't on that channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (kicked->get_fd() == client->get_fd()) {
		std::string response = ":server 481 " + client->get_nickname() + " " + channelName + " :You cannot kick yourself\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}

	std::string kickMessage = ":" + client->get_nickname() + " KICK " + channelName + " " + nickname + " :" + reason + "\r\n";
	server.sendToAllClientsInChannel(client->get_fd(), kickMessage, channelName);

	kicked->removeChannel(channelName);
	if (channel->checkOperator(kicked->get_fd()))
		channel->removeOperator(kicked->get_fd());
	channel->removeUser(kicked->get_fd());
}