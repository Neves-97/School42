#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
	public:
		Weapon();
		~Weapon();
		Weapon(std::string type);
		const std::string &getType();
		void  setType(std::string type);

	private:

		std::string _type;
};

#endif