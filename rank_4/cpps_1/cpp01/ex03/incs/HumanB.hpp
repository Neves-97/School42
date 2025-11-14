#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include "HumanA.hpp"

class HumanB
{
	public:

	HumanB (std::string bname);
	~HumanB();
	void attack();
	void	setWeapon(Weapon &equipment);


	private:

		std::string 		_name;
		Weapon			*_weapon;



};


#endif