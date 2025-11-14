#include "../incs/Includes.hpp"

AMateria::AMateria(): _type("Default") {}

AMateria::AMateria(std::string const &type): _type(type) {}

AMateria::AMateria(const AMateria &src): _type("Default") {
    *this = src;
}

AMateria& AMateria::operator=(const AMateria &src) {
    if (this != &src) {
        _type = src.getType(); // Direct assignment
    }
    return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter &target) {
    (void) target;
}
