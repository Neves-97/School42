#include "../incs/Harl.hpp"

Harl::Harl() {

}

Harl::~Harl() {

}

void Harl::info(void) {

	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;

}

void Harl::debug(void) {

	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::warning(void) {

	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {

	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}


void Harl::complain(std::string level) {
    // Convert the level string to lowercase
    for (size_t i = 0; i < level.length(); ++i) {
        level[i] = std::tolower(level[i]);
    }

    // Map from strings to member function pointers
    std::map<std::string, void (Harl::*)(void)> complaints;
    complaints["debug"] = &Harl::debug;
    complaints["info"] = &Harl::info;
    complaints["warning"] = &Harl::warning;
    complaints["error"] = &Harl::error;

    // Find the corresponding function and call it if found
    std::map<std::string, void (Harl::*)(void)>::iterator it = complaints.find(level);
    if (it != complaints.end()) {
        (this->*(it->second))();
    } else {
        std::cout << "Invalid complaint!" << std::endl;
    }
}