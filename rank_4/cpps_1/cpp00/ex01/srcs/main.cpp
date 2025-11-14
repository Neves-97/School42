#include "../incs/PhoneBook.hpp"

// int main() {
//     PhoneBook pBook;

//     while (true) {
//         pBook.showInstructions();

//         std::string input;
//         std::cout << "-> ";
//         std::getline(std::cin, input);

//         if (input == "EXIT") {
//             std::cout << "Exiting PhoneBook\n";
//             break;
//         } else if (input == "ADD") {
//             pBook.addContact();
//         } else if (input == "SEARCH") {
//             pBook.showContactList();
//         } else {
//             std::cout << "Invalid input\n" << std::endl;
//         }
//     }

//     return 0;
// }

int main() {
    PhoneBook pBook;

    while (true) {
        pBook.showInstructions();

        std::string input;
        std::cout << "-> ";
        std::getline(std::cin, input);

        if (input == "EXIT") {
            std::cout << "Exiting PhoneBook\n";
            break;
        } else if (input == "ADD") {
            pBook.addContact();
        } else if (input == "SEARCH") {
            pBook.showContactList();
            std::cout << "Enter the index of the contact you want to search for: ";
            std::getline(std::cin, input);
            if (pBook.validateIndex(input)) {
            } else {
                std::cout << "invalid index" << std::endl;
            }
        } else {
            std::cout << "Invalid input\n" << std::endl;
        }
    }

    return 0;
}


// int main() { ... }: This is the main entry point of the program. 
// It returns an integer indicating the program's exit status.

// PhoneBook pb;: This line declares an instance of the PhoneBook class 
// named pb. It creates an object of type PhoneBook, which represents a 
// phone book containing contacts.

// while (true) { ... }: This is an infinite loop that continues until 
// it is explicitly exited with a break statement.

// pb.showInstructions();: This line calls the showInstructions method 
// of the PhoneBook object pb. It displays instructions to the user on 
// how to interact with the phone book.

// std::string input;: Declares a string variable named input to 
// store the user's input.

// std::cout << "-> ";: Displays a prompt -> to indicate that the program 
// is waiting for user input.

// std::getline(std::cin, input);: Reads a line of input from the standard 
// input (keyboard) and stores it in the input variable.

// if (input == "EXIT") { ... } else if (input == "ADD") { ... } 
// else if (input == "SEARCH") { ... } else { ... }: This block of code 
// checks the value of the input variable to determine the user's choice. 
// If the input is "EXIT", the program exits the loop and terminates. 
// If the input is "ADD", it calls the addContact method of the 
// PhoneBook object to add a new contact. If the input is "SEARCH", 
// it calls the showContactList method of the PhoneBook object to search 
// for a contact. If the input is none of the above, it displays 
// "Invalid input" and loops back to prompt the user again.

// return 0;: Indicates that the program executed successfully and 
// returns 0 as the exit status.