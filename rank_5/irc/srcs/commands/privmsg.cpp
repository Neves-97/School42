#include "../../incs/commands.hpp"
#include "../../incs/client.hpp"
#include "../../incs/server.hpp"
#include "../../incs/channel.hpp"

std::vector<Channel *> Server::searchChannel(std::string channel_name)
{
	std::vector<Channel *> channels;
	for (std::vector<Channel *>::iterator it = _channels.begin(); it != _channels.end(); ++it)
	{
		if ((*it)->getName() == channel_name)
			channels.push_back(*it);
	}
	return channels;
}

std::vector<Client *> Server::searchClient(std::string client_name)
{
	std::vector<Client *> clients;
	for (std::vector<Client *>::iterator it = _clients.begin(); it != _clients.end(); ++it)
	{
		if ((*it)->get_nickname() == client_name)
			clients.push_back(*it);
	}
	return clients;
}

void Command::privmsg(Client *client, std::string target, const std::string &msg, Server &server)
{
	const std::string serverName = "localhost"; // nao sei mas ta a dar

	if (target.empty() || msg.empty()) {
		client->send_message(":" + serverName + " 411 " + client->get_nickname() + " :No recipient or message specified\r\n");
		return;
	}
	std::string fullMessage = ":" + client->get_nickname() + "!" + client->get_name() + "@" + client->get_host() + " PRIVMSG " + target + " :" + msg + "\r\n";
	if (target[0] == '#') {
		Channel *channel = server.getChannelByName(target);
		if (channel) {
			if (!client->checkInChannel(target, client->getChannels())) {
				client->send_message(":" + serverName + " 404 " + client->get_nickname() + " " + target + " :Cannot send to channel\r\n");
				return;
			}
			server.sendToAllClientsInChannel(client->get_fd(), fullMessage, target);
		} else {
			client->send_message(":" + serverName + " 403 " + client->get_nickname() + " " + target + " :No such channel\r\n");
		}
	} else {
		Client *targetClient = server.searchClientByNick(target);
		if (targetClient) {
			targetClient->send_message(fullMessage);
		} else {
			client->send_message(":" + serverName + " 401 " + client->get_nickname() + " " + target + " :No such nick/channel\r\n");
		}
	}
}
