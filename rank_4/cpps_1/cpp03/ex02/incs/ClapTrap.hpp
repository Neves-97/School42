#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {

	public:

        ClapTrap();
	    ClapTrap(std::string name);
        ClapTrap(ClapTrap const &obj);
        ClapTrap &operator=(ClapTrap const &obj);
	    ~ClapTrap();

        std::string getName();
        int getHitPoints() const;
        int getEnergyPoints() const;
        int getAttackDamage() const;

        void setName(const std::string name);
        void setHitPoints(int hp);
        void setEnergyPoints(int mn);
        void setAttackDamage(int ad);

	    void attack(const std::string& target);
	    void takeDamage(unsigned int amount);
	    void beRepaired(unsigned int amount);

	protected:

        std::string _name;
		int    _hitPoints;
		int	   _energyPoints;
		int    _attackDamage;

};

#endif
