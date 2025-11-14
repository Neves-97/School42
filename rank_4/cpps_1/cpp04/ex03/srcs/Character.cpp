#include "../incs/Includes.hpp"

Character::Character(std::string name): _name(name) {
    std::cout << "Character: " << _name << " was created" << std::endl;
    for (int i = 0; i < 4; i++) {
        (this->_inventory)[i] = 0;
    }
}


Character::Character(const Character& src): _name(src.getName() + "_src") {
    std::cout << "Character: " << _name << " was created from src of " << src._name << std::endl;
    for (int i = 0; i < 4; i++) {
        if ((src._inventory)[i])
            (this->_inventory)[i] = (src._inventory)[i]->clone();
        else
            (this->_inventory)[i] = 0;
    }
}

Character& Character::operator=(const Character& src) {
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i])
            delete this->_inventory[i];
        if (src._inventory[i])
            this->_inventory[i] = (src._inventory[i])->clone();
    }
    return (*this);
}

Character::~Character() {
    std::cout << "Character: " << this->_name << " was destroyed" << std::endl;
    for (int i = 0; i < 4; i++) {
        if ((this->_inventory)[i]) {
            delete (this->_inventory)[i];
        }
    }
}

std::string const& Character::getName() const {
    return (this->_name);
}

void Character::equip(AMateria* materia) {
    int i = 0;

    if (!materia) {
        std::cout << "Character: " << this->_name << " tried to equip an invalid materia" << std::endl;
        return;
    }
    while ((this->_inventory)[i] != 0 && i < 4)
        i++;
    if (i >= 4) {
        std::cout << "Character: " << this->_name << " can't equip more than 4 Materia" << std::endl;
        return;
    }
    (this->_inventory)[i] = materia;
    std::cout << "Character: " << this->_name << " equipped materia " << materia->getType() << " in slot " << i << std::endl;
}

void Character::use(int index, ICharacter& target) {
    if (index < 0 || index >= 4 || !(this->_inventory)[index]) {
        std::cout << "nothing found to use at index " << index << std::endl;
        return;
    }
    ((this->_inventory)[index])->use(target);
}

void Character::unequip(int index) {
    if (index < 0 || index >= 4)
        std::cout << "Character: " << this->_name << " tried to unequip nothing at invalid slot " << index << std::endl;
    else if (!(this->_inventory)[index])
        std::cout << "Character: " << this->_name << " has nothing equipped at slot " << index << " so he can't unequip it" << std::endl;
    else {
        AMateria* ptr = (this->_inventory)[index];
        std::cout << "Character: " << this->_name << " unequipped " << ptr->getType() << " at slot " << index << std::endl;
        (this->_inventory)[index] = 0;
    }
}


AMateria* Character::getMateria(int index) {
    return (this->_inventory)[index];
}
