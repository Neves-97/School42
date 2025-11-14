#include "../incs/Dog.hpp"

Dog::Dog() : Animal() {
    this->_type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj) {
    *this = obj;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &obj) {
    if (this != &obj)
        this->_type = obj._type;
    std::cout << "Dog assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "***Woof Woof***" << std::endl;
}