#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{   
    public:

        Animal();
        Animal(const Animal &obj);
        Animal &operator=(const Animal &obj);
        virtual ~Animal();
        std::string getType() const;
        virtual void makeSound() const = 0;

    protected:

        std::string _type;

};

#endif


// This line declares makeSound() as a pure virtual function by adding = 0 
// at the end. A class that contains at least one pure virtual function becomes 
// abstract in C++. Abstract classes cannot be instantiated, and attempting to 
// instantiate them directly will result in a compilation error.


// The pure virtual function (virtual void makeSound() const = 0;) 
// in Animal makes the class abstract.
// An abstract class cannot be instantiated directly.
// You can still instantiate classes that derive from Animal (e.g., Dog and Cat),
//  as long as they provide implementations for makeSound().