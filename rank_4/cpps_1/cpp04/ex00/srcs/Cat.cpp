#include "../incs/Cat.hpp"

Cat::Cat() : Animal() {
    this->_type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj){
    *this = obj;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &obj) {
    if (this != &obj)
        this->_type = obj._type;
    std::cout << "Cat assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "***Miauuu Miauuu***" << std::endl;
}