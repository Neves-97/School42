#include "../../incs/server.hpp"
#include "../../incs/channel.hpp"
#include "../../incs/commands.hpp"
#include "../../incs/client.hpp"

void Command::part(Server& server, Client *client, const std::string& message)
{
	std::string channel_name;
	std::string hold;
	std::istringstream iss(message);
	iss >> hold; // "PART"
	iss >> channel_name;

	if (channel_name.empty())
	{
		std::string response = ":server 461 " + client->get_nickname() + " PART :Not enough parameters\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (!server.checkChannelName(channel_name))
	{
		std::string response = ":server 403 " + client->get_nickname() + " " + channel_name + " :No such channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (!client->checkInChannel(channel_name, client->getChannels()))
	{
		std::string response = ":server 442 " + client->get_nickname() + " " + channel_name + " :You're not on that channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}

	Channel *channel = server.getChannelByName(channel_name);
	channel->removeUser(client->get_fd());
	client->removeChannel(channel_name);

	std::string part_message = ":" + client->get_nickname() + "!" + client->get_name() + "@localhost PART " + channel_name + "\r\n";
	send(client->get_fd(), part_message.c_str(), part_message.length(), 0);
	channel->sendToAllInChannel(server, part_message);

	if (channel->getUsers().empty())
		client->removeChannel(channel_name);
}
