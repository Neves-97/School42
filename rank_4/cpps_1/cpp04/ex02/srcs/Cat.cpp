#include "../incs/Cat.hpp"

Cat::Cat() : Animal() {
    this->_type = "Cat";
    this->_brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj){
    this->_brain = new Brain(*obj._brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &obj) {
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

Cat::~Cat() {
    delete this->_brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "***Miauuu Miauuu***" << std::endl;
}

Brain* Cat::getBrain() const {
    return this->_brain;
}