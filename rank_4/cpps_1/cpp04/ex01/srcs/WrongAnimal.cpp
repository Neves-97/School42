#include "../incs/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type ("WrongAnimal") {
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) {
    *this = obj;
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj) {
    if (this != &obj)
        this->_type = obj._type;
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const {
    return _type;
}

void WrongAnimal::makeSound() const {
    std::cout << "***beep boop, i am wrong***" << std::endl;
}