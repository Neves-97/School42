#include "../incs/Zombie.hpp"

void	randomChump( std::string name ) {
	
    Zombie zombie(name);
    zombie.announce();
}


// Here's a detailed explanation of how this works:

// Stack Allocation: The Zombie object zombie is created as a local variable within the randomChump function. Local variables are allocated on the stack.
// Automatic Destruction: The Zombie object zombie will be automatically destroyed when the randomChump function returns, as stack-allocated objects are automatically cleaned up when they go out of scope.
// Important Characteristics
// Memory Management: Since the Zombie object is allocated on the stack, you don't need to manually manage memory. The object is automatically destroyed when it goes out of scope.
// Lifetime: The lifetime of the Zombie object is limited to the duration of the randomChump function call. Once the function exits, the Zombie object is destroyed.