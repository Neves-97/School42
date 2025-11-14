#include "../incs/Fixed.hpp"

int main( void ) {

	Fixed		a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	// return 0;

}

// Fixed a;:

//     Calls the default constructor, initializing a with a _fixed_point of 0.

// Fixed const b(10);:

//     Calls the integer constructor, initializing b with the fixed-point representation of 10.

// Fixed const c(42.42f);:

//     Calls the float constructor, initializing c with the fixed-point representation of 42.42.

// Fixed const d(b);:

//     Calls the copy constructor, initializing d with the same value as b.

// a = Fixed(1234.4321f);:

//     Calls the assignment operator, assigning a the fixed-point representation of 1234.4321f.

// Output Statements:

//     The << operator prints the fixed-point numbers as floating-point values.
//     The toInt() method converts the fixed-point numbers back to integers and prints them.