#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <cctype>
#include <cstdio>

class	PhoneBook {

	private:
		
		int		_index;
		int			_i;
		Contact	contacts[8];

	public:

	void	showInstructions(void);
			PhoneBook(void);
	void 	addContact();
	void	showContactList(void);
	int  validateIndex(std::string input);

};

int checkNumber(const std::string& input);
int checkInput(const std::string& input);

#endif

// #ifndef PHONEBOOK_HPP and #define PHONEBOOK_HPP: These are include guards, similar to what 
// we discussed earlier in Contact.hpp. They prevent multiple definitions and linker errors 
// by ensuring that the contents of the header file are only included once in a translation unit.

// #include "Contact.hpp": This line includes the header file Contact.hpp, which contains the 
// declaration of the Contact class. Including it here allows PhoneBook.hpp to use Contact objects.

// #include <iostream>, #include <cctype>, #include <cstdio>: These lines include necessary standard 
// libraries. <iostream> provides input/output stream functionality, <cctype> provides functions for 
// character handling (e.g., toupper()), and <cstdio> provides C-style input/output operations.

// int checkNumber(const std::string& input); and int checkInput(const std::string& input);: These are 
// function declarations for checkNumber and checkInput functions. These functions are likely utility 
// functions used within the PhoneBook class for input validation.

// class PhoneBook { ... };: This defines a class named PhoneBook. Inside the class, there are private 
// member variables and public member functions.

// Private member variables:
// _index and _i: These variables are of type int and are used to manage the index and count of 
// contacts in the phone book.
// contacts: This is an array of Contact objects, allowing the PhoneBook class to store up to 8 contacts.

// Public member functions:
// showInstructions: This function displays instructions for using the phone book.
// PhoneBook: This is the constructor of the PhoneBook class.
// addContact: This function allows adding a new contact to the phone book.
// showContactList: This function allows searching for a contact in the phone book.
// validateIndex: This function performs validation during contact search.

// #endif: This marks the end of the include guard block.