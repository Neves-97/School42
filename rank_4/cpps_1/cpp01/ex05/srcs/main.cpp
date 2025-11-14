#include "../incs/Harl.hpp"

int main() {
    Harl harl;
    std::string level;

    std::cout << "Enter the complaint level (DEBUG, INFO, WARNING, ERROR): ";
    std::cin >> level;

    harl.complain(level);

    return 0;
}

// This header file declares the Harl class, which is responsible for managing complaints at different levels.
// It includes necessary headers like <iostream>, <string>, and <map>.
// The class declares a constructor, a destructor, and a complain member function.
// Additionally, it declares private member functions debug, info, warning, and error, which 
// represent different levels of complaints.
// Harl.cpp:

// This source file defines the member functions of the Harl class.
// The constructor and destructor are defined with empty bodies.
// The info, debug, warning, and error functions print messages representing different levels of complaints.
// The complain function dynamically selects the appropriate complaint level based on the input string and 
// calls the corresponding member function using a map of member function pointers.
// main.cpp:

// This source file contains the main function, which serves as the entry point of the program.
// It creates an instance of the Harl class.
// It prompts the user to enter a complaint level (DEBUG, INFO, WARNING, or ERROR) and reads the input.
// It then calls the complain function of the Harl instance to process the complaint based on the input level.
// Overall, your project demonstrates the use of classes, member functions, maps, and user input processing 
// to manage complaints at different levels effectively. The use of dynamic function selection based on user 
// input adds flexibility to handle various types of complaints without the need for conditional statements. 
// Additionally, the project adheres to good programming practices by organizing code into separate header and 
// source files and providing meaningful output messages.


// std::map<std::string, void (Harl::*)(void)> complaints;
// This line declares a map named complaints.
// The map has keys of type std::string and values of type pointer to member functions of class Harl that take no 
// arguments and return void.
// Initialization:

// cpp
// Copy code
// complaints["DEBUG"] = &Harl::debug;
// complaints["INFO"] = &Harl::info;
// complaints["WARNING"] = &Harl::warning;
// complaints["ERROR"] = &Harl::error;
// Here, you are populating the map with key-value pairs.
// Each key is a string representing a complaint level (e.g., "DEBUG", "INFO").
// The corresponding value is a pointer to the member function of the Harl class that handles that specific complaint level.
// Lookup and Invocation:

// cpp
// Copy code
// std::map<std::string, void (Harl::*)(void)>::iterator it = complaints.find(level);
// if (it != complaints.end()) {
//     (this->*(it->second))();
// } else {
//     std::cout << "You have to specify a valid <complain>!!" << std::endl;
// }
// You look up the complaint level entered by the user in the complaints map.
// If a corresponding entry is found (it != complaints.end()), you dereference the iterator to get the 
// pointer to the member function (it->second) and call it on the current instance of Harl using the 
// pointer-to-member-function syntax (this->*(it->second))().
// If the complaint level is not found in the map, you print an error message.
// In summary, std::map is a key-value container that allows efficient lookup of values based on keys. 
// In your code, it is used to map complaint levels to member functions of the Harl class, allowing 
// dynamic dispatch of complaints based on their levels. This approach provides flexibility and 
// extensibility to handle various types of complaints without the need for explicit conditional statements.


