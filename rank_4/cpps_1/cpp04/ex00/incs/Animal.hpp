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
        virtual void makeSound() const;

    protected:

        std::string _type;

};

#endif


// In inheritance, destructors are called in reverse order of construction.
// Key Points:

//     When an object of a derived class is destroyed, the derived class's 
//     destructor is called first.
//     Then, the base class's destructor is called after the derived class's 
//     destructor finishes.
//     This ensures that resources specific to the derived class are cleaned up 
//     first, followed by resources for the base class.

// Example:

// class Base {
// public:
//     ~Base() { std::cout << "Base destructor called\n"; }
// };

// class Derived : public Base {
// public:
//     ~Derived() { std::cout << "Derived destructor called\n"; }
// };

// When you delete a Derived object:

//     Derived destructor is called.
//     Base destructor is called afterward.

// Key Concept:

// Always ensure the base class destructor is marked **virtual** for proper cleanup 
// when using polymorphism.

// When using polymorphism, if the base class destructor is not marked virtual, 
// only the base class destructor will be called when deleting a derived object 
// via a base class pointer. This can lead to incomplete cleanup of the derived class.

// By marking the base class destructor as virtual, you ensure both the derived
//  and base class destructors are called, ensuring proper resource cleanup.

// Yes, virtual in polymorphism is also used to enable method overriding.

// When a method is marked virtual in the base class, the derived class can 
// override it. The correct method (derived or base) is called based on the actual 
// object type, even when using a base class pointer.

// This allows for dynamic dispatch, meaning the most specific method is called at 
// runtime.

// class Animal {
// public:
//     virtual void makeSound() {  // virtual keyword enables overriding
//         std::cout << "Animal sound" << std::endl;
//     }
// };

// class Dog : public Animal {
// public:
//     void makeSound() override {  // override method in derived class
//         std::cout << "Bark!" << std::endl;
//     }
// };

// int main() {
//     Animal* animal = new Dog();  // Base class pointer to Dog object
//     animal->makeSound();         // Calls Dog's makeSound() due to virtual

//     delete animal;
// }

// Output:

// plaintext

// Bark!

// Here, because makeSound() is virtual in Animal, the Dog's makeSound() 
// is called, even though animal is of type Animal*.