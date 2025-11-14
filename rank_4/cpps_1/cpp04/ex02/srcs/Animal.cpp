#include "../incs/Animal.hpp"

Animal::Animal() : _type("Plain old Animal") {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &obj) {
    this->_type = obj._type;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &obj) {
    if (this != &obj)
        this->_type = obj._type;
    std::cout << "Animal assignment operator called" << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
    return _type;
}