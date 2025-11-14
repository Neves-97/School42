#include "../incs/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &equipment){
	_name = name;
	_weapon = &equipment;
}

HumanA::~HumanA() {

}

void	HumanA::attack() {

	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}