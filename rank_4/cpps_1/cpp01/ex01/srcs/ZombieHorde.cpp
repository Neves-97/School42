#include "../incs/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {

    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; ++i)
        horde[i].setName(name);
    return horde;
}

// Zombie* zombieHorde(int numZombies, std::string zombieName) {

//     (void) zombieName;
//     (void) numZombies;
//     return NULL;
// }