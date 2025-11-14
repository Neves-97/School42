#include "../incs/Animal.hpp"
# include "../incs/Cat.hpp"
# include "../incs/Dog.hpp"
# include "../incs/WrongCat.hpp"
# include "../incs/WrongAnimal.hpp"

// int main()
// {
// 	{	
// 		std::cout << "\e[1;35m====================Constructing======================\033[0m" << std::endl;
// 		const Animal* ani = new Animal();
// 		const Animal* j = new Dog();
// 		const Animal* i = new Cat();
// 		std::cout << "\e[1;35m=====================Testing=========================\033[0m" << std::endl;
// 		std::cout << j->getType() << " " << std::endl;
// 		std::cout << i->getType() << " " << std::endl;
// 		ani->makeSound();
// 		i->makeSound(); //will output the cat sound!
// 		j->makeSound();
// 		std::cout << "\e[1;35m====================Deconstructing===================\033[0m" << std::endl;
// 		delete ani;
// 		delete i;
// 		delete j;
// 	}
// 	std::cout << "\n\n\e[1;36m====================WrongAnimal======================\033[0m\n\n" << std::endl;
// 	{
// 		std::cout << "\e[1;31m====================Constructing======================\033[0m" << std::endl;
// 		const WrongAnimal *wrgan = new WrongAnimal();
// 		const WrongAnimal *wrn = new WrongCat();
// 		const WrongCat wrnc;
// 		std::cout << "\e[1;31m=====================Testing=========================\033[0m" << std::endl;
// 		std::cout << wrgan->getType() << " " << std::endl;
// 		std::cout << wrn->getType() << " " << std::endl;
// 		std::cout << wrnc.getType() << " " << std::endl;
// 		wrgan->makeSound();
// 		wrn->makeSound(); 
// 		wrnc.makeSound(); //will output the wrong cat sound!
// 		std::cout << "\e[1;31m====================Deconstructing===================\033[0m" << std::endl;
// 		delete wrgan;
// 		delete wrn;
// 	}
//     return 0;
// }

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    std::cout << "Testing with proper Animal, Dog, and Cat classes:\n";
    
    const Animal* ani = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "\nTypes:\n";
    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;

    std::cout << "\nSounds:\n";
    dog->makeSound(); // Should output dog sound
    cat->makeSound(); // Should output cat sound
    ani->makeSound(); // Should output generic animal sound or empty, depending on your implementation

    std::cout << "\nTesting with WrongAnimal and WrongCat classes:\n";

    const WrongAnimal* wrongani = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
	const WrongCat * wrongCat1 = new WrongCat();

    std::cout << "\nTypes:\n";
    std::cout << wrongani->getType() << " " << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;
	std::cout << wrongCat1->getType() << " " << std::endl;

    std::cout << "\nSounds:\n";
    wrongani->makeSound(); // Should output generic wrong animal sound
    wrongCat->makeSound(); // Should output wrong animal sound, not cat sound
	wrongCat1->makeSound(); // Should ouytput the wrong cat sound

    // Clean up memory
    delete ani;
    delete dog;
    delete cat;
    delete wrongani;
    delete wrongCat;
	delete wrongCat1;

    return 0;
}


// int main() {

//     Animal() = new Animal;
// }