#include "../incs/Zombie.hpp"

Zombie* newZombie( std::string name ) {

		Zombie *new_zombie = new Zombie(name);
		return new_zombie;
}

// Heap Allocation: The new operator dynamically allocates memory on the heap and returns a pointer to the allocated memory. The Zombie object is created in this allocated memory.
// Returning a Pointer: The function returns a pointer (Zombie*) to the newly allocated Zombie object. This pointer itself is a local variable within the newZombie function, but the actual Zombie 
// object it points to resides in the heap.
// Important Notes
// Memory Management: Since the Zombie object is allocated on the heap, it is your responsibility to manage the memory. Specifically, you need to ensure that the allocated memory is properly freed 
// using delete when the Zombie object is no longer needed. Failing to do so will result in a memory leak.
// Lifetime: Objects allocated on the heap persist until they are explicitly deallocated using delete. In contrast, objects allocated on the stack are automatically destroyed when they go out of scope.
