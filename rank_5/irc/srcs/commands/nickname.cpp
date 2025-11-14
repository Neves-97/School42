/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nickname.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:40:38 by micarrel          #+#    #+#             */
/*   Updated: 2025/02/24 19:40:38 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/commands.hpp"
#include "../../incs/client.hpp"
#include "../../incs/server.hpp"
# include <cctype>

bool Server::validNickname(const std::string &nickname) const
{
	for (std::vector<Client *>::const_iterator it = _clients.begin(); it != _clients.end(); ++it) {
		if ((*it)->get_nickname() == nickname) {
			return true;
		}
	}
	return false;
}

void Command::nickname(Server &server, std::vector<Client *> &clients, Client &client, const std::string &nickname) {
	(void)clients;

	std::string oldNick = client.get_nickname();

	if (nickname.empty()) {
		std::string response = ":localhost 431 * :No nickname given\r\n";
		client.send_message(response);
		return;
	}

	if (server.validNickname(nickname)) {
		std::string response = ":localhost 433 * " + nickname + " :Nickname is already in use\r\n";
		client.send_message(response);
		return;	
	}

	if (isdigit(nickname[0]) || nickname[0] == '#' || nickname[0] == ':') {
		std::string response = ":localhost 432 * " + nickname + " :Erroneous nickname\r\n";
		client.send_message(response);
		return;
	}

	client.set_nickname(nickname);

	std::string nickChangeMsg = ":" + oldNick + "!" + client.get_name() + "@localhost NICK :" + nickname + "\r\n";
	client.send_message(nickChangeMsg);

	if (!client.getChannels().empty()) {
		server.sendToAllClientsInChannel(client.get_fd(), nickChangeMsg, client.getChannels()[0]);
	}
}