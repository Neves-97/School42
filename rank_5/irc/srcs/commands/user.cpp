#include "../../incs/commands.hpp"
#include "../../incs/client.hpp"
#include "../../incs/server.hpp"
# include <cctype>

bool Server::validUsername(const std::string &username) const
{
	for (std::vector<Client *>::const_iterator it = _clients.begin(); it != _clients.end(); ++it) {
		if ((*it)->get_name() == username) {
			return true;
		}
	}
	return false;
}

void Command::username(Server &server, std::vector<Client *> &clients, Client &client, const std::string &username) {
	(void) clients;

	if (server.validUsername(username)) {
		std::string response = ":server 433 * " + username + " :Nickname is already in use\r\n";
		client.send_message(response);
		return;
	}

	if (isdigit(username[0]) || username[0] == '#') {
		std::string response = ":server 432 * " + username + " :Erroneous nickname\r\n";
		client.send_message(response);
		return;
	}

	client.set_name(username);
}