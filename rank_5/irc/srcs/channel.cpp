
#include "../incs/channel.hpp"
#include "../incs/server.hpp"
#include "../incs/client.hpp"

Channel::Channel()
{
	_name = "";
	_topic = "";
	_password = "";
	_mode = "";
	_user_limits = INT_MAX;
	_private = false;
	_invite_only = false;
	_password_only = false;
	_limit_user_on = false;
}

Channel::Channel(std::string name, int owner_fd)
{
	_name = name;
	_topic = "";
	_password = "";
	_user_limits = INT_MAX;
	_private = false;
	_invite_only = false;
	_password_only = false;
	_limit_user_on = false;
	_operators.push_back(owner_fd);
}

Channel::~Channel()
{
}

void Channel::addUser(int fd) {
	if (std::find(_users.begin(), _users.end(), fd) == _users.end()) {
		_users.push_back(fd);
	}
}

void Channel::sendToAllInChannel(Server &server, std::string message) {
	std::vector<Client *> Tempclients = server.getClients();
	for (std::vector<int>::iterator it = _users.begin(); it != _users.end(); ++it) {
		for (std::vector<Client *>::iterator it2 = Tempclients.begin(); it2 != Tempclients.end(); ++it2) {
			if ((*it) == (*it2)->get_fd()) {
				(*it2)->send_message(message);
			}
		}
	}
}

void Channel::broadcastMessage(Client *client, std::string message, Server &server)
{
	std::string broadcast = client->get_nickname() + ": " + message + "\n";
	sendToAllInChannel(server, broadcast);
}

bool Channel::isPasswordOnly() {
	return _password_only;
}

bool Channel::checkOperator(int fd)
{
	for (std::vector<int>::iterator it = _operators.begin(); it != _operators.end(); ++it)
	{
		if ((*it) == fd)
			return true;
	}
	return false;
}

void Channel::removeUser(int fd) {
	std::vector<int>::iterator it = std::find(_users.begin(), _users.end(), fd);
	if (it != _users.end()) {
		_users.erase(it);
	}
}

void Channel::removeOperator(int fd)
{
	for (std::vector<int>::iterator it = _operators.begin(); it != _operators.end(); ++it)
	{
		if ((*it) == fd)
		{
			_operators.erase(it);
			break;
		}
	}
}

bool Channel::isUserInChannel(int fd) {
	return std::find(_users.begin(), _users.end(), fd) != _users.end();
}

// void Channel::printOperators()
// {
// 	for (std::vector<std::string>::iterator it = _operators.begin(); it != _operators.end(); ++it)
// 	{
// 		std::cout << *it << std::endl;
// 	}
// }

void Channel::addUserToOperators(int fd) {
	if (std::find(_operators.begin(), _operators.end(), fd) == _operators.end()) {
		_operators.push_back(fd);
	}
}

std::string Channel::getName() {
	return _name;
}

std::string Channel::getTopic() {
	return _topic;
}

std::string Channel::getPassword() {
	return _password;
}

std::string Channel::getMode() {
	return _mode;
}

std::vector<int> Channel::getUsers() {
	return _users;
}

std::vector<int> Channel::getInvites() {
	return _invites;
}

bool Channel::isUserInvited(int fd)
{
	return std::find(_invites.begin(), _invites.end(), fd) != _invites.end();
}

void Channel::removeInvite(int fd)
{
	std::vector<int>::iterator it = std::find(_invites.begin(), _invites.end(), fd);
	if (it != _invites.end())
	{
		_invites.erase(it);
	}
}

std::vector<int> Channel::getOperators() {
	return _operators;
}

size_t Channel::getUserLimits() {
	return _user_limits;
}

bool Channel::isLimitUserOn() {
	return _limit_user_on;
}

bool Channel::isPrivate() {
	return _private;
}

bool Channel::isInviteOnly() {
	return _invite_only;
}

void Channel::setName(std::string name) {
	_name = name;
}

void Channel::setTopic(std::string topic) {
	_topic = topic;
}

void Channel::setPassword(std::string password) {
	_password = password;
}

void Channel::setMode(std::string mode) {
	_mode = mode;
}

void Channel::setUsers(std::vector<int> users) {
	_users = users;
}

void Channel::setOperators(std::vector<int> operators) {
	_operators = operators;
}

void Channel::setUserLimits(size_t user_limits) {
	_user_limits = user_limits;
}

void Channel::setLimitUserOn(bool limit_user_on) {
	_limit_user_on = limit_user_on;
}

// void Channel::setPrivate(bool private) {
// 	_private = private;
// }

void Channel::setInviteOnly(bool invite_only) {
	_invite_only = invite_only;
}

void Channel::setPasswordOnly(bool password_only) {
	_password_only = password_only;
}

void Channel::setTopicOnly(bool topic_only) {
	_topic_only = topic_only;
}

void Channel::addInvite(int fd) {
	if (std::find(_invites.begin(), _invites.end(), fd) == _invites.end()) {
		_invites.push_back(fd);
	}
}

bool Channel::isTopicOnly() {
	return _topic_only;
}
