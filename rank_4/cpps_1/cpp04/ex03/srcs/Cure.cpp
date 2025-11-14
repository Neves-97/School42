#include "../incs/Includes.hpp"

Cure::Cure(): AMateria("cure") {}

Cure::Cure(const Cure &src): AMateria(src) {
    *this = src;
}

Cure& Cure::operator=(const Cure &src) {
    if (this != &src) {
        _type = src.getType(); // Direct assignment
    }
    return *this;
}

Cure::~Cure() {}


AMateria *Cure::clone() const {
    AMateria *cure = new Cure;
    return cure;
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

