#include "../incs/Fixed.hpp"
int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

// 	return 0;
}

// Fixed a;:

//     Creates an object a of type Fixed. This calls the default constructor, setting _fixed_point to 0.

// Fixed b(a);:

//     Creates an object b using the copy constructor, initializing b with the value of a's _fixed_point.

// Fixed c;:

//      

// c = b;:

//     Assigns the value of b to c using the copy assignment operator.

// Output:

//     Prints the _fixed_point values of a, b, and c to the console, which should all be 0.