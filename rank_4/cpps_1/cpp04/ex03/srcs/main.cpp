#include "../incs/Includes.hpp"
#include "../incs/Character.hpp"

// int main()
// {
// 	IMateriaSource* materia = new MateriaSource();
// 	materia->learnMateria(new Ice());
// 	materia->learnMateria(new Cure());
// 	ICharacter* pencilgon = new Character("pencilgon");
// 	AMateria* tmp;
// 	tmp = materia->createMateria("ice");
// 	pencilgon->equip(tmp);
// 	tmp = materia->createMateria("cure");
// 	pencilgon->equip(tmp);
// 	ICharacter* bilac = new Character("bilac");
// 	pencilgon->use(0, *bilac);
// 	pencilgon->use(1, *bilac);

// 	delete bilac;
// 	delete pencilgon;
// 	delete materia;
// 	return 0;
// }

#include <iostream>
#include "IMateriaSource.hpp" // Include your headers as necessary
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

int main() {
    IMateriaSource* materia = new MateriaSource();
    materia->learnMateria(new Ice());
    materia->learnMateria(new Cure());
    ICharacter* pencilgon = new Character("pencilgon");
    AMateria* tmp;
    tmp = materia->createMateria("ice");
    pencilgon->equip(tmp);
    tmp = materia->createMateria("cure");
    pencilgon->equip(tmp);
    ICharacter* bilac = new Character("bilac");
    pencilgon->use(0, *bilac);
    pencilgon->use(1, *bilac);
    // Testing Character deep copy using the copy constructor
    Character* copyPencilgon = new Character(*(Character*)pencilgon);  
    std::cout << "Testing copy constructor:\n";
    copyPencilgon->use(0, *bilac);  // Should use Ice
    copyPencilgon->use(1, *bilac);  // Should use Cure
    // Testing assignment operator
    Character assignPencilgon("assignPencilgon");
    assignPencilgon = *(Character*)pencilgon;  
    std::cout << "Testing assignment operator:\n";
    assignPencilgon.use(0, *bilac);  // Should use Ice
    assignPencilgon.use(1, *bilac);  // Should use Cure

    // Clean up memory
    delete bilac;
    delete pencilgon;
    delete copyPencilgon;
    delete materia;
    
    return 0;
}



// 1. Creating the MateriaSource

// cpp

// IMateriaSource* materia = new MateriaSource();

//     Purpose: This line creates an instance of MateriaSource, which implements the IMateriaSource interface.
//     Memory Management: The new keyword allocates memory for a MateriaSource object on the heap, and a pointer to this object is stored in the materia variable. This means you'll need to delete this object later to prevent memory leaks.

// 2. Learning Materias

// cpp

// materia->learnMateria(new Ice());
// materia->learnMateria(new Cure());

//     Purpose: Here, the MateriaSource object learns two types of materias: Ice and Cure.
//     Memory Management: Each new expression creates an Ice and a Cure object on the heap. The learnMateria method presumably stores these objects within the MateriaSource instance.

// 3. Creating a Character

// cpp

// ICharacter* pencilgon = new Character("pencilgon");

//     Purpose: This line creates a new character named "pencilgon".
//     Memory Management: Similar to the MateriaSource, this allocates memory for a Character object, and a pointer to this object is assigned to pencilgon.

// 4. Creating and Equipping Materias

// cpp

// AMateria* tmp;
// tmp = materia->createMateria("ice");
// pencilgon->equip(tmp);
// tmp = materia->createMateria("cure");
// pencilgon->equip(tmp);

//     Purpose:
//         The first line declares a pointer tmp of type AMateria.
//         The next line calls createMateria on the materia object to create an instance of the Ice materia. This instance is assigned to tmp and then equipped by pencilgon.
//         The same process is repeated for the Cure materia.
//     Memory Management:
//         The createMateria method likely returns a pointer to a new AMateria (either Ice or Cure).
//         If pencilgon is managing its own AMateria pointers (for example, storing them in an array), it must ensure to store or manage the tmp pointer properly to avoid losing the reference to the created objects.

// 5. Creating Another Character

// cpp

// ICharacter* bilac = new Character("bilac");

//     Purpose: This line creates another character named "bilac".
//     Memory Management: As with the previous characters, this allocates memory for the Character object and assigns the pointer to bilac.

// 6. Using Materias

// cpp

// pencilgon->use(0, *bilac);
// pencilgon->use(1, *bilac);

//     Purpose: The use method on pencilgon is called with the indices of the materias equipped (0 for Ice and 1 for Cure), and it targets bilac.
//     Functionality: This simulates pencilgon using the Ice and Cure materias on bilac. The exact effects depend on how the use method is implemented in the Character class.

// 7. Cleaning Up

// cpp

// delete bilac;
// delete pencilgon;
// delete materia;

//     Purpose: These lines deallocate the memory previously allocated for bilac, pencilgon, and materia.
//     Memory Management: This is crucial to prevent memory leaks. Each delete statement ensures that the resources used by each object are freed.

// 8. Return Statement

// cpp

// return 0;

//     Purpose: This line indicates that the program executed successfully. The main function returns an integer to the operating system, typically 0 for success.

// Summary

//     This main function effectively demonstrates the functionality of your MateriaSource, Character, and AMateria classes, ensuring that objects are created, used, and cleaned up properly.
//     The key areas to ensure there are no memory leaks include properly managing pointers, especially those returned from createMateria, and ensuring that the Character class correctly handles the deep copy of its materias in its copy constructor and assignment operator.