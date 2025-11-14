#include "../incs/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    this->_type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj) {
    *this = obj;
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &obj) {
    if (this != &obj)
        this->_type = obj._type;
    std::cout << "WrongCat assignment operator called" << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "*** Heyoo this is the WrongCat baby***" << std::endl;
}