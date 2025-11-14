#include "../../incs/server.hpp"
#include "../../incs/channel.hpp"
#include "../../incs/commands.hpp"
#include "../../incs/client.hpp"

void Command::who(Server &server, Client *client, const std::string &message) {
	std::istringstream iss(message);
	std::string command, channel_name;
	iss >> command;
	iss >> channel_name;

	if (!channel_name.empty()) {
		Channel *channel = server.getChannelByName(channel_name);
		if (!channel) {
			std::string response = ":server 403 " + client->get_nickname() + " " + channel_name + " :No such channel\r\n";
			client->send_message(response);
			return;
		}

		std::vector<int> user_fds = channel->getUsers();
		for (size_t i = 0; i < user_fds.size(); ++i) {
			Client *user = server.find_client_by_fd(user_fds[i]);
			if (user) {
				std::string status = channel->checkOperator(user->get_fd()) ? "@" : "";
				std::string response = ":server 352 " + client->get_nickname() + " " + channel->getName() + " " +
									   user->get_name() + " localhost server " +
									   user->get_nickname() + " H" + status + " :0 " + user->get_name() + "\r\n";
				client->send_message(response);
			}
		}
		std::string end_response = ":server 315 " + client->get_nickname() + " " + channel->getName() + " :End of WHO list\r\n";
		client->send_message(end_response);
	} else {
		std::vector<Channel *> channels = server.getChannels();
		for (size_t i = 0; i < channels.size(); ++i) {
			Channel *channel = channels[i];
			std::vector<int> user_fds = channel->getUsers();
			for (size_t j = 0; j < user_fds.size(); ++j) {
				Client *user = server.find_client_by_fd(user_fds[j]);
				if (user) {
					std::string status = channel->checkOperator(user->get_fd()) ? "@" : "";
					std::string response = ":server 352 " + client->get_nickname() + " " + channel->getName() + " " +
										   user->get_name() + " localhost server " +
										   user->get_nickname() + " H" + status + " :0 " + user->get_name() + "\r\n";
					client->send_message(response);
				}
			}
		}
		std::string end_response = ":server 315 " + client->get_nickname() + " * :End of WHO list\r\n";
		client->send_message(end_response);
	}
}






