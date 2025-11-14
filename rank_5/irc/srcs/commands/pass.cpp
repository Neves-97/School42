#include "../../incs/commands.hpp"
#include "../../incs/client.hpp"
#include "../../incs/server.hpp"

void Command::password(Server server, Client &client, const std::string &password) 
{
	if (client.get_authenticated()) {
		std::string response = ":server 462 " + client.get_nickname() + " :You are already authenticated\r\n";
		client.send_message(response);
		return;
	}

	std::cout << "Password: " << password << std::endl;

	if (password == server.get_password()) {
		client.set_authenticated(true);
		std::string welcomeMessage = "Welcome to the IRC Network\r\n";
		client.send_message(welcomeMessage);
	}
	else {
		std::string response = ":server 464 " + client.get_nickname() + " :Invalid password\r\n";
		client.send_message(response);
	}
}

