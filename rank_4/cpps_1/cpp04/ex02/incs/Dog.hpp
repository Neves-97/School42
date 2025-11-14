#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    public: 

        Dog();
        Dog(const Dog &obj);
        ~Dog();
        Dog &operator=(const Dog &obj);
        virtual void	makeSound() const;
         // Add public methods to interact with the Brain
        // void setIdea(int index, const std::string & idea);
        // std::string getIdea(int index) const;
        Brain* getBrain() const;

    private:
        Brain* _brain;
};

#endif