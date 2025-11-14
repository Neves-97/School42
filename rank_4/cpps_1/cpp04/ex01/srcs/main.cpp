#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main() {
//     std::cout << "Creating a Dog and a Cat:\n";

//     // Create one Dog and one Cat
//     Dog* dog1 = new Dog();
//     Cat* cat1 = new Cat();

//     // Test their sound
//     std::cout << "\nOriginal Animal Sounds:\n";
//     dog1->makeSound();  // Should output "Woof!"
//     cat1->makeSound();  // Should output "Meow!"

//     // Test deep copy for Dog
//     std::cout << "\nCreating a copy of the Dog (deep copy):\n";
//     Dog* dog2 = new Dog(*dog1);  // Using copy constructor

//     // Test deep copy for Cat
//     std::cout << "\nCreating a copy of the Cat (deep copy):\n";
//     Cat* cat2 = new Cat(*cat1);  // Using copy constructor

//     // Verifying that the Brain instances are different
//     std::cout << "\nVerifying deep copy (comparing Brain pointers):\n";
//     std::cout << "Dog1 Brain address: " << dog1->getBrain() << std::endl;
//     std::cout << "Dog2 Brain address: " << dog2->getBrain() << std::endl;

//     std::cout << "Cat1 Brain address: " << cat1->getBrain() << std::endl;
//     std::cout << "Cat2 Brain address: " << cat2->getBrain() << std::endl;

//     // Modify the Brain of the copied dog
//     std::cout << "\nModifying Dog2's Brain:\n";
//     dog2->getBrain()->setIdea(0, "I want a bone!");  // Modify first idea in Dog2's Brain
//     std::cout << "Dog2's Brain first idea: " << dog2->getBrain()->getIdea(0) << std::endl;
//     std::cout << "Dog1's Brain first idea (should not change): " << dog1->getBrain()->getIdea(0) << std::endl;

//     // Delete the original and copied animals
//     std::cout << "\nDeleting the original and copied animals:\n";
//     delete dog1;
//     delete dog2;
//     delete cat1;
//     delete cat2;

//     return 0;
// }


// #include "Dog.hpp"
// #include "Cat.hpp"
// #include <iostream>

// int main() {
//     const int array_size = 6;  // Example size, half Dog objects, half Cat objects

//     // Create an array of Animal pointers (half Dog, half Cat)
//     Animal* animals[array_size];

//     // Fill the first half with Dogs and the second half with Cats
//     for (int i = 0; i < array_size / 2; i++) {
//         animals[i] = new Dog();
//     }
//     for (int i = array_size / 2; i < array_size; i++) {
//         animals[i] = new Cat();
//     }

//     // Verify that the appropriate sounds are made
//     std::cout << "\nAnimal sounds:\n";
//     for (int i = 0; i < array_size; i++) {
//         animals[i]->makeSound();
//     }

//     // Test deep copy functionality for Dog
//     std::cout << "\nTesting deep copy for Dog:\n";
//     Dog* originalDog = new Dog();
//     originalDog->getBrain()->setIdea(0, "I want a bone!");

//     // Perform deep copy for Dog
//     Dog* copiedDog = new Dog(*originalDog);
//     std::cout << "Original Dog's Brain first idea: " << originalDog->getBrain()->getIdea(0) << std::endl;
//     std::cout << "Copied Dog's Brain first idea: " << copiedDog->getBrain()->getIdea(0) << std::endl;

//     // Modify copied Dog's Brain and verify original remains unchanged
//     copiedDog->getBrain()->setIdea(0, "I want to chase a ball!");
//     std::cout << "\nAfter modifying Copied Dog's Brain:\n";
//     std::cout << "Original Dog's Brain first idea: " << originalDog->getBrain()->getIdea(0) << std::endl;
//     std::cout << "Copied Dog's Brain first idea: " << copiedDog->getBrain()->getIdea(0) << std::endl;

//     // Test deep copy functionality for Cat
//     std::cout << "\nTesting deep copy for Cat:\n";
//     Cat* originalCat = new Cat();
//     originalCat->getBrain()->setIdea(0, "I want to sleep!");

//     // Perform deep copy for Cat
//     Cat* copiedCat = new Cat(*originalCat);
//     std::cout << "Original Cat's Brain first idea: " << originalCat->getBrain()->getIdea(0) << std::endl;
//     std::cout << "Copied Cat's Brain first idea: " << copiedCat->getBrain()->getIdea(0) << std::endl;

//     // Modify copied Cat's Brain and verify original remains unchanged
//     copiedCat->getBrain()->setIdea(0, "I want to eat!");
//     std::cout << "\nAfter modifying Copied Cat's Brain:\n";
//     std::cout << "Original Cat's Brain first idea: " << originalCat->getBrain()->getIdea(0) << std::endl;
//     std::cout << "Copied Cat's Brain first idea: " << copiedCat->getBrain()->getIdea(0) << std::endl;

//     // Clean up deep copy test objects
//     delete originalDog;
//     delete copiedDog;
//     delete originalCat;
//     delete copiedCat;

//     // Delete all animals in the array
//     std::cout << "\nDeleting all animals:\n";
//     for (int i = 0; i < array_size; i++) {
//         delete animals[i];  // Properly delete Dogs and Cats as Animals
//     }

//     return 0;
// }


#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

// int main() {
//     {
//         std::cout << "\nCreating and testing deep copy for Dog:\n";
        
//         Dog basic;
//         basic.getBrain()->setIdea(0, "I want to fetch!");
        
//         // Copy Dog using copy constructor (deep copy test)
//         Dog tmp = basic;  // Calls the copy constructor
        
//         std::cout << "Basic Dog's Brain first idea: " << basic.getBrain()->getIdea(0) << std::endl;
//         std::cout << "Copied Dog's Brain first idea: " << tmp.getBrain()->getIdea(0) << std::endl;

//         // Modify the copied dog's brain
//         tmp.getBrain()->setIdea(0, "I want to sleep!");
//         std::cout << "\nAfter modifying the copied dog's brain:\n";
//         std::cout << "Basic Dog's Brain first idea: " << basic.getBrain()->getIdea(0) << std::endl;
//         std::cout << "Copied Dog's Brain first idea: " << tmp.getBrain()->getIdea(0) << std::endl;
    
	
//         std::cout << "\nCreating and testing deep copy for Cat:\n";
        
//         Cat basicCat;
//         basicCat.getBrain()->setIdea(0, "I want to sleep!");

//         // Copy Cat using copy constructor (deep copy test)
//         Cat tmpCat = basicCat;  // Calls the copy constructor
        
//         std::cout << "Basic Cat's Brain first idea: " << basicCat.getBrain()->getIdea(0) << std::endl;
//         std::cout << "Copied Cat's Brain first idea: " << tmpCat.getBrain()->getIdea(0) << std::endl;

//         // Modify the copied cat's brain
//         tmpCat.getBrain()->setIdea(0, "I want to eat!");
//         std::cout << "\nAfter modifying the copied cat's brain:\n";
//         std::cout << "Basic Cat's Brain first idea: " << basicCat.getBrain()->getIdea(0) << std::endl;
//         std::cout << "Copied Cat's Brain first idea: " << tmpCat.getBrain()->getIdea(0) << std::endl;
//     }

//     return 0;
// }

int main() {
    {
        std::cout << "\nCreating and testing deep copy for Dog:\n";
        
        Dog basic;
        basic.getBrain()->setIdea(0, "I want to fetch!");
        
        Dog tmp;  // Create an uninitialized Dog
        tmp = basic;  // Calls the assignment operator
        
        std::cout << "Basic Dog's Brain first idea: " << basic.getBrain()->getIdea(0) << std::endl;
        std::cout << "Assigned Dog's Brain first idea: " << tmp.getBrain()->getIdea(0) << std::endl;

        // Modify the copied dog's brain
        tmp.getBrain()->setIdea(0, "I want to sleep!");
        std::cout << "\nAfter modifying the assigned dog's brain:\n";
        std::cout << "Basic Dog's Brain first idea: " << basic.getBrain()->getIdea(0) << std::endl;
        std::cout << "Assigned Dog's Brain first idea: " << tmp.getBrain()->getIdea(0) << std::endl;

        std::cout << "\nCreating and testing deep copy for Cat:\n";
        
        Cat basicCat;
        basicCat.getBrain()->setIdea(0, "I want to sleep!");

        Cat tmpCat;  // Create an uninitialized Cat
        tmpCat = basicCat;  // Calls the assignment operator
        
        std::cout << "Basic Cat's Brain first idea: " << basicCat.getBrain()->getIdea(0) << std::endl;
        std::cout << "Assigned Cat's Brain first idea: " << tmpCat.getBrain()->getIdea(0) << std::endl;

        // Modify the copied cat's brain
        tmpCat.getBrain()->setIdea(0, "I want to eat!");
        std::cout << "\nAfter modifying the assigned cat's brain:\n";
        std::cout << "Basic Cat's Brain first idea: " << basicCat.getBrain()->getIdea(0) << std::endl;
        std::cout << "Assigned Cat's Brain first idea: " << tmpCat.getBrain()->getIdea(0) << std::endl;
    }
}



// #include <iostream>
// #include "Dog.hpp"  // Assuming the Dog class includes a Brain member

// int main() {
//     std::cout << "Creating basic Dog...\n";
//     Dog basic;  // Should call Animal constructor, Brain constructor, Dog constructor
    
//     std::cout << "Creating tmp Dog by copying basic...\n";
//     {
//         Dog tmp = basic;  // Should call Animal copy constructor, Brain copy constructor, Dog copy constructor
        
//         std::cout << "Comparing brain addresses of basic and tmp: \n";
//         std::cout << "Brain of basic: " << basic.getBrain() << std::endl;  // Assuming getBrain() returns pointer to Brain
//         std::cout << "Brain of tmp: " << tmp.getBrain() << std::endl;
        
//         std::cout << "Tmp is about to go out of scope...\n";
//     }  // Destructor of tmp should be called: Brain destructor, Dog destructor, Animal destructor
    
//     std::cout << "Tmp is out of scope. Check if basic is still fine.\n";

//     return 0;
// }


// Without the virtual keyword on the Animal destructor, deleting an Animal* 
// that points to a derived object (like a Dog or Cat) will not call the derived 
// class's destructor. This leads to incomplete destruction of the object and 
// potential memory leaks because resources allocated in the derived class won't be released.
// Why Must the Animal Destructor Be Virtual?

//     Polymorphic Deletion: When you delete an object through a base class pointer, 
// 	C++ determines which destructor to call based on whether the base class 
// 	destructor is virtual.

//     Proper Resource Cleanup: A virtual destructor ensures that the destructors 
// 	of derived classes are called in the correct order, allowing for proper 
// 	cleanup of resources allocated in derived classes.