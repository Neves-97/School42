#include <iostream>

int main() {

	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << &str << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;
	std::cout << str << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;

}

// Initialization:

// You initialize a string variable str with the value "HI THIS IS BRAIN".
// Pointer and Reference:

// You declare a pointer stringPTR that points to the address of the string str.
// You declare a reference stringREF that refers to the string str.
// Address Display:

// You print the address of the string using three different methods:
// Using the address-of operator & with the string variable str.
// Using the pointer stringPTR.
// Using the reference stringREF.
// Content Display:

// You print the content of the string using two different methods:
// Dereferencing the pointer stringPTR using the * operator.
// Directly accessing the string through the reference stringREF.
// Overall, your code effectively demonstrates the usage of pointers and references with a string object. 
// It correctly displays the address of the string and its content using both pointers and references. 
// You have followed the specifications outlined in the subject. Well done!