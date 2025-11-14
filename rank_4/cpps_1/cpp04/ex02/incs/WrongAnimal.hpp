#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal 
{

    public: 

        WrongAnimal();
        WrongAnimal(WrongAnimal const &obj);
        WrongAnimal &operator=(const WrongAnimal &obj);
        virtual ~WrongAnimal();
        std::string getType() const;
        void makeSound() const;
    
    protected:

        std::string _type;
};

#endif