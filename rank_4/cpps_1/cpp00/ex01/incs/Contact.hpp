#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>


class Contact
{
	public:

		void	fName(std::string f_name);
    	void	lName(std::string l_name);
    	void	nName(std::string n_name);
    	void	pNumber(std::string p_number);
    	void	dSecret(std::string d_secret);
		void	showFirsLastNick();
		void	showContact();

	private:

		std::string		_first_name;
		std::string		_last_name;
		std::string		_nickname;
		std::string		_phone_number;
		std::string		_darkest_secret;
};

#endif

// #ifndef CONTACT_HPP and #define CONTACT_HPP: These are include guards, ensuring that the 
// contents of the header file are only included once in a translation unit. 
// This prevents multiple definitions and linker errors.

// #include <iostream>: This line includes the input/output stream library, which is necessary 
// for using standard input/output operations.

// #include <iomanip>: This line includes the I/O manipulators library, which provides tools 
// for formatting output, such as setting field width.

// #include <string>: This line includes the string library, which provides facilities for 
// working with strings.

// class Contact { ... };: This defines a class named Contact. Inside the class, there are public 
// member functions and private member variables.

// Public member functions:
// fName, lName, nName, pNumber, and dSecret: These functions are used to set the first name, last name, 
// nickname, phone number, and darkest secret of a contact, respectively.
// showFirsLastNick: This function is responsible for displaying the first name, last name, and 
// nickname of a contact.
// showContact: This function is responsible for displaying all details of a contact.

// Private member variables:
// _first_name, _last_name, _nickname, _phone_number, and _darkest_secret: These
//  variables store the first name, last name, nickname, phone number, and darkest 
//  secret of a contact, respectively. They are declared as private to encapsulate the 
//  internal state of a Contact object.

// #endif: This marks the end of the include guard block.