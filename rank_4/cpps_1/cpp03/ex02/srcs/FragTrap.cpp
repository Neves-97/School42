#include "../incs/FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
    this->_name = "DefaultFrag";
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "\e[1;33m FragTrap ---> Default constructor called \033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "\e[1;33m FragTrap ---> Name constructor called for \033[0m" << "\e[1;32m<" << this->_name << ">\033[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj) {
    std::cout << "\e[1;33m FragTrap ---> Copy constructor called \033[0m" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "\e[1;33m FragTrap ---> Destructor called \033[0m" << "\e[1;32m<" << this->_name << ">\033[0m" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &obj) {
    if (this != &obj) {
        ClapTrap::operator=(obj);
    }
    std::cout << "\e[1;33m FragTrap ---> Assignment operator called \033[0m" << std::endl;
    return *this;
}

void FragTrap::highFivesGuys() const {
    std::cout << "\e[1;33m FragTrap ---> High fives, guys come and get it ! \033[0m" << "\e[1;32m<" << this->_name << ">\033[0m" << std::endl;
}
