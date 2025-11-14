#ifndef ICE_HPP
#define ICE_HPP

#include "Includes.hpp"

class Ice: public AMateria {

    public:

        Ice();
        Ice(const Ice &src);
        Ice &operator=(const Ice &src);
        ~Ice();
             
        AMateria *clone() const;
        void use(ICharacter &target);

    private:

        std::string _type;
};

#endif