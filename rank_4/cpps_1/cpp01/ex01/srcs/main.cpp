#include "../incs/Zombie.hpp"

// int main() {
//     int numZombies = 10;
//     std::string zombieName = "bigg";
//     Zombie* zombieArmy = zombieHorde(numZombies, zombieName);
//     for (int i = 0; i < numZombies; ++i)
//         zombieArmy[i].announce();
//     if (zombieArmy == NULL)
//         return 1;
//     delete[] zombieArmy;
//     return 0;
// }


int main() {
    int numZombies = 10;
    std::string zombieName = "bigg";
    Zombie* zombieArmy = zombieHorde(numZombies, zombieName);
    if (zombieArmy == NULL) {
        std::cerr << "Memory allocation failed" << std::endl;
        return 1;
    }
    for (int i = 0; i < numZombies; ++i)
        zombieArmy[i].announce();
    delete[] zombieArmy;
    return 0;
}


// Zombie Class:

// You have defined a Zombie class with a default constructor, destructor, and a member function announce that prints 
// the name of the zombie followed by the phrase "BraiiiiiiinnnzzzZ...".
// Additionally, you have a setName function to set the name of the zombie.
// zombieHorde Function:

// Your zombieHorde function allocates memory for an array of Zombie objects on the heap using new[].
// It initializes each zombie's name using the provided name parameter.
// The function returns a pointer to the first zombie in the allocated array.
// Testing:

// Your main function serves as a test case for the zombieHorde function. It creates a horde of zombies with 
// the specified number and name, then iterates through the array, making each zombie announce itself.
// You correctly deallocate the memory allocated for the zombie array using delete[] to prevent memory leaks.
// Memory Management:

// You've properly managed memory allocation and deallocation, ensuring that memory allocated with new[] is properly 
// released with delete[] to avoid memory leaks.
// Overall, your project appears to meet the requirements outlined in the subject. It demonstrates an understanding of 
// dynamic memory allocation, array initialization, and memory deallocation in C++. Your code structure is clear and concise, 
// making it easy to understand and maintain. Well done!