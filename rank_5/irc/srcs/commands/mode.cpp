#include "../../incs/server.hpp"
#include "../../incs/channel.hpp"
#include "../../incs/commands.hpp"
#include "../../incs/client.hpp"

void Command::mode(Client *client, const std::string &message, Server &server) {
	std::string channel_name;
	std::string mode;
	std::string nickname;
	std::string hold;
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
	if (!channel->checkOperator(client->get_fd())) {
		std::string response = ":server 482 " + client->get_nickname() + " " + channel_name + " :You're not channel operator\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (mode == "+o")
		plus_o(client, message, server);
	else if (mode == "-o")
		minus_o(client, message, server);
	else if (mode == "+i")
		plus_i(client, message, server);
	else if (mode == "-i")
		minus_i(client, message, server);
	else if (mode == "+t")
		plus_t(client, message, server);
	else if (mode == "-t")
		minus_t(client, message, server);
	else if (mode == "+k")
		plus_k(client, message, server);
	else if (mode == "-k")
		minus_k(client, message, server);
	else if (mode == "+l")
		plus_l(client, message, server);
	else if (mode == "-l")
		minus_l(client, message, server);
	else {
		std::string response = ":server 472 " + client->get_nickname() + " " + mode + " :is unknown mode char to me\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
	}
}