#include "../incs/Contact.hpp"

void	Contact::fName(std::string f_name) {
	this->_first_name = f_name;
}

void	Contact::lName(std::string l_name) {
	this->_last_name = l_name;
}

void	Contact::nName(std::string n_name) {
	this->_nickname = n_name;
}

void	Contact::pNumber(std::string p_number) {
	this->_phone_number = p_number;
}

void	Contact::dSecret(std::string d_secret) {
	this->_darkest_secret = d_secret;
}

void Contact::showFirsLastNick() {
    std::string formatted_first_name = this->_first_name.substr(0, 9);
    std::string formatted_last_name = this->_last_name.substr(0, 9);
    std::string formatted_nickname = this->_nickname.substr(0, 9);

    if (this->_first_name.length() > 9) {
        formatted_first_name += ".";
    }
    if (this->_last_name.length() > 9) {
        formatted_last_name += ".";
    }
    if (this->_nickname.length() > 9) {
        formatted_nickname += ".";
    }

    std::cout << std::setw(10) << std::right << formatted_first_name << "|";
    std::cout << std::setw(10) << std::right << formatted_last_name << "|";
    std::cout << std::setw(10) << std::right << formatted_nickname;
}

void	Contact::showContact() {

	std::cout << "\nFirst Name: " << this->_first_name << std::endl;
	std::cout << "Last Name: " << this->_last_name << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone Number: " << this->_phone_number << std::endl;
	std::cout << "Darkest Secret: " << this->_darkest_secret << std::endl;
}
