#include "../incs/Includes.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::Ice(const Ice &src): AMateria(src) {
    *this = src;
}

Ice& Ice::operator=(const Ice &src) {
    if (this != &src) {
        _type = src.getType(); // Direct assignment
    }
    return *this;
}

Ice::~Ice() {}


AMateria *Ice::clone() const {
    AMateria *ice = new Ice;
    return ice;
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
