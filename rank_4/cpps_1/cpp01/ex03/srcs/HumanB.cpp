#include "../incs/HumanB.hpp"

HumanB::HumanB (std::string bname) {

	_name = bname;
	_weapon = NULL;
}

HumanB::~HumanB() {

}

void	HumanB::attack() {
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon " << std::endl;
}


void	HumanB::setWeapon(Weapon &equipment) {

	_weapon = &equipment;

}
