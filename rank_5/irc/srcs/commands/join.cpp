/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:35:18 by micarrel          #+#    #+#             */
/*   Updated: 2025/03/03 12:35:18 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/server.hpp"
#include "../../incs/channel.hpp"
#include "../../incs/commands.hpp"
#include "../../incs/client.hpp"

void Command::join_cmd(Client *client, const std::string &message, Server &server)
{
	std::string channel_name;
	std::string password;
	std::istringstream iss(message);
	std::string command;
	iss >> command;
	iss >> channel_name;

	if (client->get_nickname().empty() || client->get_name().empty())
	{
		std::string response = ":server 451 " + client->get_nickname() + " :You must set a nickname/user before joining a channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (channel_name.empty())
	{
		std::string response = ":server 461 " + client->get_nickname() + " JOIN :No channel name provided\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (channel_name[0] != '#')
	{
		std::string response = ":server 403 " + client->get_nickname() + " " + channel_name + " :Invalid channel name\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (!server.checkChannelName(channel_name))
	{
		Channel *new_channel = new Channel(channel_name, client->get_fd());
		server.addChannel(new_channel);
		new_channel->addUserToOperators(client->get_fd());
	}
	if (client->checkInChannel(channel_name, client->getChannels()))
	{
		std::string response = ":server 442 " + client->get_nickname() + " " + channel_name + " :You are already in this channel\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	Channel *channel = server.getChannelByName(channel_name);
	if (channel->isPasswordOnly())
	{
		iss >> password;
		if (password.empty())
		{
			std::string response = ":server 473 " + client->get_nickname() + " " + channel_name + " :Password required\r\n";
			send(client->get_fd(), response.c_str(), response.length(), 0);
			return;
		}
		if (channel->getPassword() != password)
		{
			std::string response = ":server 475 " + client->get_nickname() + " " + channel_name + " :Invalid password\r\n";
			send(client->get_fd(), response.c_str(), response.length(), 0);
			return;
		}
	}
	if (channel->isLimitUserOn() && channel->getUsers().size() >= channel->getUserLimits())
	{
		std::string response = ":server 471 " + client->get_nickname() + " " + channel_name + " :Channel is full\r\n";
		send(client->get_fd(), response.c_str(), response.length(), 0);
		return;
	}
	if (channel->isInviteOnly())
	{
		if (!channel->isUserInvited(client->get_fd()))
		{
			std::string response = ":server 473 " + client->get_nickname() + " " + channel_name + " :You are not invited to this channel\r\n";
			send(client->get_fd(), response.c_str(), response.length(), 0);
			return;
		}
	}
	if (channel->getUsers().size() == 0)
		channel->addUserToOperators(client->get_fd());

	client->addChannel(channel_name);
	channel->addUser(client->get_fd());

	std::string response = ":server 322 " + client->get_nickname() + " " + channel_name + " :You have joined the channel\r\n";
	send(client->get_fd(), response.c_str(), response.length(), 0);

	std::string broadcast = ":" + client->get_nickname() + "!" + client->get_name() + " JOIN " + channel_name + "\r\n";
	channel->sendToAllInChannel(server, broadcast);

	std::string nick_list;
	std::vector<int> user_fds = channel->getUsers();
	for (size_t i = 0; i < user_fds.size(); ++i)
	{
		int fd = user_fds[i];
		Client* user = server.find_client_by_fd(fd);
		if (!user)
			continue;
		if (channel->checkOperator(fd))
			nick_list += "@" + user->get_nickname() + " ";
		else
			nick_list += user->get_nickname() + " ";
	}
	
	if (!nick_list.empty() && nick_list[nick_list.size() - 1] == ' ')
		nick_list.erase(nick_list.size() - 1);

	std::string names_reply = ":server 353 " + client->get_nickname() + " = " + channel_name + " :" + nick_list + "\r\n";
	send(client->get_fd(), names_reply.c_str(), names_reply.length(), 0);

	std::string end_names = ":server 366 " + client->get_nickname() + " " + channel_name + " :End of /NAMES list.\r\n";
	send(client->get_fd(), end_names.c_str(), end_names.length(), 0);

	std::string welcome_message = ":server 001 " + client->get_nickname() + " :Welcome to the channel " + channel_name + "\r\n";
	send(client->get_fd(), welcome_message.c_str(), welcome_message.length(), 0);
}
