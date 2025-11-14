#include "../incs/PhoneBook.hpp"

void PhoneBook::showInstructions() {
    std::cout << "\t\tEnter 1 of the 3 Valid Inputs:\nADD(Add a contact), SEARCH(Search for a contact), EXIT(Exit PhoneBook)" << std::endl;
}

PhoneBook::PhoneBook() {
    this->_index = 0;
    this->_i = 0;
}

int checkInput(const std::string& input) {
    if (input.empty() || (input.find_first_not_of(' ') == std::string::npos)) {
        std::cout << "Field cannot be empty.\n";
        return 1;
    }
    return 0;
}

int checkNumber(const std::string& input) {
    for (size_t i = 0; i < input.length(); i++) {
        if (!isdigit(input[i])) {
            std::cout << "Must contain only numbers" << std::endl;
            return 1;
        }
    }
    return 0;
}

void PhoneBook::addContact() {
    std::string input;

    if (this->_i >= 8)
        this->_i = 0;

    std::cout << "Enter First Name -> ";
    std::getline(std::cin, input);
    if (checkInput(input))
        return;
    this->contacts[this->_i].fName(input);

    std::cout << "Enter Last Name -> ";
    std::getline(std::cin, input);
    if (checkInput(input))
        return;
    this->contacts[this->_i].lName(input);

    std::cout << "Enter Nickname -> ";
    std::getline(std::cin, input);
    if (checkInput(input))
        return;
    this->contacts[this->_i].nName(input);

    std::cout << "Enter Phone Number -> ";
    std::getline(std::cin, input);
    if (checkInput(input) || checkNumber(input))
        return ;
    this->contacts[this->_i].pNumber(input);

    std::cout << "Enter Deepest darkest secret-> ";
    std::getline(std::cin, input);
    if (checkInput(input))
        return;
    this->contacts[this->_i].dSecret(input);

    this->_i++;
    this->_index++;
}

int PhoneBook::validateIndex(std::string input) {
    long index;
    int result = sscanf(input.c_str(), "%ld", &index);
    if (result != 1 || index > this->_index || index < 1) {
        std::cout << "Invalid index" << std::endl;
        return 0;
    }
    this->contacts[index - 1].showContact();
    return 1;
}

void PhoneBook::showContactList() {
    std::string input;

    if (this->_index == 0) {
        std::cout << "Your Phonebook is empty!" << std::endl;
        return;
    }
    
    std::cout << "\n|      Index|      Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|--------------------------------------------|" << std::endl;
    for (int i = 0; i < std::min(this->_index, 8); i++) {
        std::cout << "|";
        std::cout << std::setw(11) << i + 1 << "|";
        this->contacts[i].showFirsLastNick();
        std::cout << "|" << std::endl;
        if (i < std::min(this->_index, 8) - 1)
            std::cout << "|--------------------------------------------|" << std::endl;
    }
    std::cout << "|--------------------------------------------|\n" << std::endl;
}


// void PhoneBook::showInstructions() { ... }: This method displays instructions 
// to the user about valid inputs for interacting with the phone book. 
// It prompts the user to enter one of three valid inputs: "ADD" to add a contact, 
// "SEARCH" to search for a contact, or "EXIT" to exit the phone book.

// PhoneBook::PhoneBook() { ... }: This is the constructor for the PhoneBook class. 
// It initializes the _index and _i member variables to 0. _index tracks the 
// number of contacts in the phone book, and _i is used as an index to add contacts.

// int checkInput(const std::string& input) { ... }: This function checks 
// if a given input string is empty or consists only of whitespace characters. 
// If the input is empty or contains only whitespace, it prints an error message 
// and returns 1; otherwise, it returns 0.

// int checkNumber(const std::string& input) { ... }: This function checks if 
// a given input string contains only digits (i.e., it represents a valid phone number). 
// If the input contains any non-digit characters, it prints an error message and returns 1; 
// otherwise, it returns 0.

// void PhoneBook::addContact() { ... }: This method allows the user to add a new contact 
// to the phone book. It prompts the user to enter the contact's first name, last name, 
// nickname, phone number, and deepest darkest secret. It uses the checkInput function 
// to validate each input and the checkNumber function to validate the phone number 
// before adding the contact to the phone book.

// int PhoneBook::validateIndex(std::string input) { ... }: This method validates 
// the user's input when searching for a contact by index. It uses sscanf to convert 
// the input string to a long integer representing the index. If the conversion is 
// successful and the index is within the valid range (1 to _index), it calls the 
// showContact method of the corresponding contact. If the conversion fails or the 
// index is invalid, it prints an error message and returns 0.

// void PhoneBook::showContactList() { ... }: This method displays all contacts in 
// the phone book along with their indices, names, last names, and nicknames. 
// It calls the showFirsLastNick method of each contact to format and display 
// their names. The contacts are displayed in a tabular format with separators 
// between each entry.