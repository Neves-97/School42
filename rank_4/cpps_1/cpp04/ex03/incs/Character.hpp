#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Includes.hpp"
#include "ICharacter.hpp"
class Character: public ICharacter {

    public:

        Character(std::string name);
        Character(const Character &src);
        Character &operator=(const Character &src);
        ~Character();
        
        std::string const &getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        AMateria* getMateria(int index);

    private:

        std::string const _name;
        AMateria* _inventory[4];
};

#endif