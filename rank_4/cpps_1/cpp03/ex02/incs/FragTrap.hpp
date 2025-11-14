#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap {
public:

    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap &obj);
    ~FragTrap();
    FragTrap &operator=(const FragTrap &obj);

    void highFivesGuys() const;
};

#endif
