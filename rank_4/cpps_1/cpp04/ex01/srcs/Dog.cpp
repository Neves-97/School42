#include "../incs/Dog.hpp"

Dog::Dog() : Animal() {
    this->_type = "Dog";
    this->_brain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj) {
    this->_brain = new Brain(*obj._brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &obj) {
    if (this != &obj) {
        this->_type = obj._type;
        
        // Deep copy the Brain object
        if (this->_brain)
            delete this->_brain;
        this->_brain = new Brain(*obj._brain);  // Deep copy
        
        std::cout << "Dog assignment operator called" << std::endl;
    }
    return *this;
}


Dog::~Dog() {
    delete this->_brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "***Woof Woof***" << std::endl;
}

Brain* Dog::getBrain() const {
    return this->_brain;
}