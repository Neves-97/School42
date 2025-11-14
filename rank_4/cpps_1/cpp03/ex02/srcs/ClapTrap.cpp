#include "../incs/ClapTrap.hpp"

ClapTrap::ClapTrap() {

    this->_name = "Default";
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
    std::cout << "\e[1;31m ClapTrap ---> Default constructor called \033[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name) {
    
    this->_name = name;
    this->_hitPoints = 10;
    this ->_energyPoints = 10;
    this->_attackDamage = 0;
    std::cout << "\e[1;31m ClapTrap ---> i choose you MR.\033[0m" << "\e[1;32m <" << this->_name << ">\033[0m" << std::endl;

}

ClapTrap::ClapTrap(const ClapTrap &obj) {

    *this = obj;
    std::cout << "\e[1;31m ClapTrap ---> Copy constructor called \033[0m" << std::endl;
}


ClapTrap &ClapTrap::operator=(const ClapTrap &obj) {
	if (this == &obj)
		return *this;
	this->_name = obj._name;
	this->_hitPoints = obj._hitPoints;
	this->_energyPoints = obj._energyPoints;
	this->_attackDamage = obj._attackDamage;
	std::cout << "\e[1;31m ClapTrap ---> Assignment operator called \033[0m" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {

    std::cout << "\e[1;31m ClapTrap ---> Destructor is summoned \033[0m" << "\e[1;32m < " << this->_name << " >\033[0m" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
    if (this->_hitPoints < 1)
    {
        std::cout << "ClapTrap ----> " << this->_name << " can't attack " 
                  << target << ", because he is dead." << std::endl;
    }
    else if (this->_energyPoints < 1)
    {
        std::cout << "ClapTrap ----> " << this->_name << " can't attack " 
                  << target << ", because he has no energy." << std::endl;
    }
    else
    {
        std::cout << "ClapTrap ----> " << this->_name << " attacks " 
                  << target << ", dealing " << this->_attackDamage << " bazilion of damage!" << std::endl;
        this->_energyPoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {

    if (this->_hitPoints < 1)
    {
        std::cout << "ClapTrap ----> " << this->_name << " is really dead " << std::endl;
    }
    if (amount >= static_cast<unsigned int>(_hitPoints)) {
        std::cout << "ClapTrap ----> About " << this->_name << "... can't kill what is already dead " << std::endl;
        _hitPoints = 0;
    } else {
        _hitPoints -= amount;
        std::cout << "ClapTrap ----> " << _name << " lost " << amount << " hit points!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_hitPoints <= 0) {
        std::cout << "ClapTrap ----> " << _name << " is dead and cannot be brought back to life." << std::endl;
        return;
    }

    if (this->_energyPoints <= 0) {
        std::cout << "ClapTrap ----> " << _name << " has no energy to repair himself." << std::endl;
        return;
    }

    unsigned int maxHp = 100;
    unsigned int repairableAmount = std::min(amount, maxHp - _hitPoints);

    _hitPoints += repairableAmount;
    _energyPoints--;

    std::cout << "ClapTrap ----> " << _name << " was revitalized " << repairableAmount << " points." << std::endl;
}

void ClapTrap::setName(std::string name) {

    this->_name = name;
}

void ClapTrap::setHitPoints(int hp) {

    this->_hitPoints = hp;
}

void ClapTrap::setEnergyPoints(int mn) {

    this->_energyPoints = mn;
}

void ClapTrap::setAttackDamage(int ad) {

    this->_attackDamage = ad;
}


std::string ClapTrap::getName() {

    return this->_name;
}
        
int ClapTrap::getHitPoints() const {

    return this->_hitPoints;
}

int ClapTrap::getEnergyPoints() const {

    return this->_energyPoints;
}

int ClapTrap::getAttackDamage() const {

    return this->_attackDamage;
}

