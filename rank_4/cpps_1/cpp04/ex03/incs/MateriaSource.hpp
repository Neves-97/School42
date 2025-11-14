#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "Includes.hpp"

class MateriaSource: public IMateriaSource {

    public:

        MateriaSource();
        MateriaSource(const MateriaSource &src);
        MateriaSource &operator=(const MateriaSource &src);
        ~MateriaSource();
        void learnMateria(AMateria* materia);
        AMateria* createMateria(std::string const& type);

    private:

    AMateria* _inventory[4];
};

#endif