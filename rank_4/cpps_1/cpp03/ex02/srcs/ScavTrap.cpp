#include "../incs/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default_ScavTrap") {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "\e[1;36m ScavTrap ---> Constructor Invocated \033[0m" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "\e[1;36m ScavTrap ---> Name constructor Invocated for \033[0m" << "\e[1;34m <" << this->_name << ">\033[0m" << std::endl;
}


ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    *this = other;
    std::cout << "\e[1;36m ScavTrap ---> Copy constructor called \033[0m" << std::endl;
}

ScavTrap &ScavTrap::operator=( ScavTrap const &obj)
{
	ClapTrap::operator=(obj);
	std::cout << "\e[1;36m ScavTrap ---> Assignment operator called \033[0m" << std::endl;
	return(*this);
}

ScavTrap::~ScavTrap() {
    std::cout << "\e[1;36m ScavTrap ---> Destructor Invocated !! \033[0m" << "\e[1;33m <" << this->_name << ">\033[0m" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        std::cout << "ScavTrap ----> " << _name << " attacks " << target
                  << ", dealing " << _attackDamage << " tons of damage!" << std::endl;
        _energyPoints--;
    } else if (_energyPoints <= 0) {
        std::cout << "ScavTrap ----> " << _name << " can't attack " << target << ", no energy left." << std::endl;
    } else {
        std::cout << "ScavTrap ----> " << _name << " can't attack " << target << ", because it is dead." << std::endl;
    }
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap ----> " << _name << " is guarding dem gates!" << std::endl;
}
