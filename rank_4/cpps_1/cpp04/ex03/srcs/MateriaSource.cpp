// #include "../incs/Includes.hpp"

// MateriaSource::MateriaSource() {
//     std::cout << "Materia Source: materia source created\n";
//     for (int i = 0; i < 4; i++) {
//         this->_inventory[i] = 0;
//     }
// }

// MateriaSource::MateriaSource(MateriaSource const& src) {
//     for (int i = 0; i < 4; i++) {
//         // Deep src!
//         if (src._inventory[i])
//             this->_inventory[i] = (src._inventory[i])->clone();
//     }
//     std::cout << "Materia Source: materia source created from src\n";
// }

// MateriaSource& MateriaSource::operator=(MateriaSource const& src) {
//     for (int i = 0; i < 4; i++) {
//         if (this->_inventory[i])
//             delete this->_inventory[i];
//         if (src._inventory[i])
//             this->_inventory[i] = (src._inventory[i])->clone();
//     }
//     return (*this);
// }

// MateriaSource::~MateriaSource() {
//     for (int i = 0; i < 4; i++) {
//         if (this->_inventory[i])
//             delete this->_inventory[i];
//     }
//     std::cout << "Materia Source: materia source destroyed\n";
// }

// void MateriaSource::learnMateria(AMateria *materia) {
//     int i = 0;

//     while ((this->_inventory)[i] != 0 && i < 4)
//         i++;
//     if (i >= 4) {
//         std::cout << "Materia Source: can't learn more than 4 Materias";
//         return;
//     }
//     (this->_inventory)[i] = materia;
//     std::cout << "Materia Source: materia " << materia->getType() << " learned\n";
// }

// // AMateria* MateriaSource::createMateria(std::string const & type) {
// //     int i = 0;

// //     while ((this->_inventory)[i] && ((this->_inventory)[i])->getType() != type && i < 4)
// //         i++;
// //     if (i >= 4 || !(this->_inventory)[i]) {
// //         std::cout << "Materia Source: " << type << " materia does not exist\n";
// //         return (NULL);
// //     }
// //     std::cout << "Materia Source: materia " << type << " created\n";
// //     return (((this->_inventory)[i])->clone());
// // }

// AMateria* MateriaSource::createMateria(std::string const & type) {
//     int i = 0;

//     // Search for the requested materia type in the inventory
//     while (i < 4 && (this->_inventory)[i]) {
//         if ((this->_inventory)[i]->getType() == type) {
//             // Found the requested materia type, clone it
//             std::cout << "Materia Source: materia " << type << " created\n";
//             return ((this->_inventory)[i]->clone());
//         }
//         i++;
//     }

//     // If we reach here, the materia type does not exist
//     std::cout << "Materia Source: " << type << " materia does not exist\n";
//     return NULL; // Return NULL to indicate failure
// }


#include "../incs/Includes.hpp"
#include "../incs/MateriaSource.hpp"

MateriaSource::MateriaSource() {
    std::cout << "Materia Source: materia source created\n";
    for (int i = 0; i < 4; i++) {
        this->_inventory[i] = 0; // Initialize inventory to NULL
    }
}

MateriaSource::MateriaSource(MateriaSource const& src) {
    for (int i = 0; i < 4; i++) {
        // Deep copy of src's inventory
        if (src._inventory[i]) {
            this->_inventory[i] = src._inventory[i]->clone();
        } else {
            this->_inventory[i] = NULL; // Set to NULL if the source was empty
        }
    }
    std::cout << "Materia Source: materia source created from src\n";
}

MateriaSource& MateriaSource::operator=(MateriaSource const& src) {
    if (this != &src) { // Check for self-assignment
        for (int i = 0; i < 4; i++) {
            if (this->_inventory[i]) {
                delete this->_inventory[i]; // Free existing memory
            }
            if (src._inventory[i]) {
                this->_inventory[i] = src._inventory[i]->clone(); // Clone the new materia
            } else {
                this->_inventory[i] = NULL; // Set to NULL if the source was empty
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        delete this->_inventory[i]; // Free memory of stored materia
    }
    std::cout << "Materia Source: materia source destroyed\n";
}

void MateriaSource::learnMateria(AMateria *materia) {
    int i = 0;
    while (i < 4 && this->_inventory[i]) {
        i++; // Find the first empty slot
    }
    if (i < 4) {
        this->_inventory[i] = materia; // Add materia to inventory
        std::cout << "Materia Source: materia " << materia->getType() << " learned\n";
    } else {
        std::cout << "Materia Source: can't learn more than 4 Materias\n";
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i] && this->_inventory[i]->getType() == type) {
            std::cout << "Materia Source: materia " << type << " created\n";
            return this->_inventory[i]->clone(); // Return a clone of the found materia
        }
    }
    std::cout << "Materia Source: " << type << " materia does not exist\n";
    return NULL; // Return NULL if the materia does not exist
}
