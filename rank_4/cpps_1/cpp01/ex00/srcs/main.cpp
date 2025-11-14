#include "../incs/Zombie.hpp"

int main(void) {

	Zombie *new_zombie = newZombie("puto");
	new_zombie->announce();
	randomChump("G");
	delete new_zombie;
	return 0;
}

// Zombie Class:

// You have defined a Zombie class with a private member _name and at least a constructor and a destructor.
// The announce function prints the name of the zombie followed by the phrase "BraiiiiiiinnnzzzZ...", 
// fulfilling the requirement.
// newZombie Function:

// Your newZombie function correctly allocates a Zombie object on the heap using new and returns a pointer to it.
// Ideally, it calls the constructor that takes a string argument to initialize the name of the zombie.
// randomChump Function:

// The randomChump function creates a Zombie object on the stack with the given name and then makes it announce itself.
// You've chosen to allocate the zombie on the stack, which is implicitly deleted when the function returns. 
// This choice is justified by the subject's requirement for the zombie to be implicitly deleted at the end of the function.
// Testing:

// Your main function serves as a basic test case for both the newZombie and randomChump functions. It creates a 
// zombie using newZombie, makes it announce itself, creates another zombie using randomChump, and then deletes the 
// dynamically allocated zombie.
// Memory Management:

// You've correctly allocated memory for the zombie created with newZombie on the heap and ensured it's deleted before 
// the end of the program to prevent memory leaks.
// Overall, your project appears to be in compliance with the subject's requirements. It demonstrates an understanding 
// of memory management, class construction, and function usage in C++. Your choice to allocate zombies on the stack 
// or heap aligns well with the given requirements and provides a good example of stack and heap memory usage. Well done!

// Stack:

// The stack is a region of memory that stores function calls, local variables, and function parameters.
// Memory on the stack is managed automatically by the compiler through a mechanism known as stack frames.
// When a function is called, space is allocated on the stack for its local variables and parameters. 
// When the function returns, this space is automatically deallocated.
// Access to memory on the stack is fast, as it involves simple pointer manipulation.
// Heap:

// The heap is a region of memory used for dynamic memory allocation.
// Memory on the heap is managed manually by the programmer using functions like new and delete in C++, 
// or malloc and free in C.
// Memory allocated on the heap persists until it is explicitly deallocated by the programmer.
// Access to memory on the heap is relatively slower compared to the stack because it involves more 
// complex memory management.
// In your code:

// The newZombie function allocates memory for a Zombie object on the heap using new.
// The randomChump function creates a Zombie object on the stack, as it's declared as a local variable 
// within the function. This zombie is automatically deallocated when the function returns, demonstrating stack memory usage.
// So, the difference between the stack and heap in your code is that newZombie allocates memory on the 
// heap, while randomChump utilizes the stack for memory allocation.


// This exercise demonstrates that the private attribute _name in the Zombie class 
// cannot be accessed or modified from outside the class, preserving the encapsulation 
// principle of object-oriented programming.

// Zombie myZombie("Fred");
// myZombie._name = "George";