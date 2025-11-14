#include "../incs/Animal.hpp"
#include "../incs/Cat.hpp"
#include "../incs/Dog.hpp"
#include "../incs/WrongAnimal.hpp"
#include "../incs/WrongCat.hpp"


// int main()
// {
// 	{
// 		const Animal* dog = new Dog;
// 		const Animal* cat = new Cat;
// 		// const Animal animal;

// 		std::cout << std::endl;
// 		dog->makeSound();
// 		cat->makeSound();
// 		std::cout << std::endl;
// 		delete dog;
// 		delete cat;
// 	}
// 	return 0;
// }
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {

    // Animal* yo = new Animal
    // Create one Dog and one Cat
    Dog* dog1 = new Dog();
    Cat* cat1 = new Cat();

    // Test their sound
    std::cout << "\nAnimal Sounds:\n";
    dog1->makeSound();  // Should output "Woof!"
    cat1->makeSound();  // Should output "Meow!"

    // Test deep copy for Dog
    std::cout << "\nCreating a copy of the Dog (deep copy):\n";
    Dog* dog2 = new Dog(*dog1);  // Using copy constructor

    // Modify the Brain of the copied dog and verify deep copy
    std::cout << "\nModifying Dog2's Brain:\n";
    dog2->getBrain()->setIdea(0, "I want to chase a ball!");  // Modify first idea in Dog2's Brain
    std::cout << "Dog2's Brain first idea: " << dog2->getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog1's Brain first idea (should not change): " << dog1->getBrain()->getIdea(0) << std::endl;

    // Clean up memory
    delete dog1;
    delete dog2;
    delete cat1;

    return 0;
}
