/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:39:38 by micarrel          #+#    #+#             */
/*   Updated: 2025/02/24 19:39:38 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_HPP
# define COMMANDS_HPP

# include "client.hpp"
# include "server.hpp"
# include <iostream>
# include <string>
# include <sstream>
# include <cstdlib>
# include <unistd.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <vector>
# include <map>
# include <netdb.h>
# include <cstdio>
# include <cstring>
# include <cerrno>
# include <csignal>
# include <poll.h>
# include <sys/types.h>


class Command
{
	private:

	public:
		void nickname(Server &server, std::vector<Client *> &clients, Client &client, const std::string &nickname);
		void username(Server &server, std::vector<Client *> &clients, Client &client, const std::string &username);
		void join_cmd(Client *client, const std::string &message, Server &server);
		void password(Server server, Client &client, const std::string &password);
		void privmsg(Client *client, std::string target, const std::string &msg, Server &server);
		void kick(Client *client, const std::string &msg, Server &server);
		void invite(Server& server, Client *client, const std::string& message);
		void Topic(Server &server, Client *client, const std::string &message);
		void mode(Client *client, const std::string &message, Server &server);
		void plus_o(Client *client, const std::string &message, Server &server);
		void minus_o(Client *client, const std::string &message, Server &server);
		void plus_i(Client *client, const std::string &message, Server &server);
		void minus_i(Client *client, const std::string &message, Server &server);
		void plus_t(Client *client, const std::string &message, Server &server);
		void minus_t(Client *client, const std::string &message, Server &server);
		void plus_k(Client *client, const std::string &message, Server &server);
		void minus_k(Client *client, const std::string &message, Server &server);
		void plus_l(Client *client, const std::string &message, Server &server);
		void minus_l(Client *client, const std::string &message, Server &server);
		void who(Server &server, Client *client, const std::string &message);
		void part(Server& server, Client *client, const std::string& message);
};

# endif 