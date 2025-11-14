#include "../incs/HumanA.hpp"
#include "../incs/HumanB.hpp"
#include "../incs/Weapon.hpp"

int main() {
	{
	Weapon club = Weapon("crude spiked club");

	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	}
	{
	Weapon club = Weapon("crude spiked club");

	HumanB jim("Jim");
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
	}
	return 0;
}

// int main() {
//     {
//         Weapon club("crude spiked club");
//         HumanA bob("Bob", club);
//         bob.attack(); // Bob attacks with the club

//         club.setType("some other type of club");
//         bob.attack(); // Bob attacks with the updated club
//     }

//     {
//         HumanB jim("Jim");
//         jim.attack(); // Jim cannot attack because he has no weapon

//         Weapon club("crude spiked club");
//         jim.setWeapon(club); // Set a weapon for Jim
//         jim.attack(); // Jim attacks with the club

//         club.setType("some other type of club");
//         jim.attack(); // Jim attacks with the updated club
//     }

//     return 0;
// }



// Weapon Class:

// The Weapon class has a private member _type to store the weapon type.
// It has a default constructor, a constructor that takes a string, a destructor, and functions to get and set the weapon type.
// The getType() function returns a const reference to the weapon type string, as specified.
// HumanA Class:

// HumanA has a constructor that takes a name and a reference to a Weapon object.
// It has a destructor, which is empty in your implementation.
// The attack() function prints the name of the human along with the type of weapon they are attacking with, retrieved 
// using the getType() function of the referenced Weapon.
// HumanB Class:

// HumanB has a constructor that takes a name.
// It has a destructor, also empty in your implementation.
// The attack() function prints the name of the human along with the type of weapon they are attacking with, 
// retrieved using the getType() function of the pointed Weapon.
// It has a setWeapon() function to set the weapon for the human, which takes a reference to a Weapon object.
// Main Function:

// In the main() function, you demonstrate the usage of HumanA and HumanB objects with Weapon objects.
// First, you create a Weapon object club and use it to create a HumanA object bob. Then, you call bob.attack() to 
// demonstrate that Bob attacks with the weapon.
// Next, you create another Weapon object club and use it to create a HumanB object jim. Then, you use 
// jim.setWeapon(club) to set the weapon for Jim, and call jim.attack() to demonstrate that Jim attacks with the weapon.
// You then change the type of the weapon club and demonstrate that both Bob and Jim use the updated weapon type 
// in their attacks.
// Overall, your project effectively demonstrates the appropriate use of pointers and references in the context of 
// the HumanA, HumanB, and Weapon classes as per the specifications outlined in the subject. Well done!