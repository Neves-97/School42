#include "../../incs/server.hpp"
#include "../../incs/channel.hpp"
#include "../../incs/commands.hpp"
#include "../../incs/client.hpp"


void Command::invite(Server& server, Client *client, const std::string& message) {
	std::string channel_name;
	std::string nickname;
	std::string hold;
	std::istringstream iss(message);
	iss >> hold;
	iss >> channel_name;
	iss >> nickname;

	if (channel_name.empty()) {
		std::string response = ":server 461 " + client->get_nickname() + " INVITE :Not enough parameters\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (nickname.empty()) {
		std::string response = ":server 461 " + client->get_nickname() + " INVITE :Not enough parameters\r\n";
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
	if (!channel->checkOperator(client->get_fd())) {
		std::string response = ":server 482 " + client->get_nickname() + " " + channel_name + " :You're not channel operator\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (!server.validNickname(nickname)) {
		std::string response = ":server 401 " + client->get_nickname() + " " + nickname + " :No such nick/channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}

	Client *invited = server.searchClientByNick(nickname);
	if (!invited) {
		std::string response = ":server 401 " + client->get_nickname() + " " + nickname + " :No such nick/channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (invited->get_fd() == client->get_fd()) {
		std::string response = ":server 481 " + client->get_nickname() + " " + channel_name + " :You cannot invite yourself\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (invited->checkInChannel(channel_name, invited->getChannels())) {
		std::string response = ":server 443 " + client->get_nickname() + " " + nickname + " " + channel_name + " :User is already in this channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}

	channel->addInvite(invited->get_fd());

	std::string response = ":" + client->get_nickname() + " INVITE " + nickname + " :" + channel_name + "\r\n";
	send(invited->get_fd(), response.c_str(), response.length(), 0);

	response = ":server 341 " + client->get_nickname() + " " + nickname + " " + channel_name + "\r\n";
	send(client->get_fd(), response.c_str(), response.length(), 0);
}