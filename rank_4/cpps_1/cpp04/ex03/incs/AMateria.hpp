#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "Includes.hpp"

class ICharacter;

class AMateria {

    public: 

        AMateria();
        AMateria(std::string const &type);
        AMateria(const AMateria &src);
        AMateria &operator=(const AMateria &src);
        virtual ~AMateria();
        std::string const &getType() const;
        virtual AMateria*clone() const = 0;
        virtual void use(ICharacter &target);

    protected:

        std::string _type;
};

#endif