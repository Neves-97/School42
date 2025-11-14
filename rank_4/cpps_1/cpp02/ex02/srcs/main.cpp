#include "../incs/Fixed.hpp"

int main( void ) {

	Fixed		a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}

// division by 0

// int main() {

    
//     Fixed c(42.42f);
//     Fixed zero(0);

//     Fixed result = c / zero;


//     std::cout << "The result of the division by 0 is " << result << std::endl;


//     return 0;
// }

// Fixed a;:

//     Default constructor initializes a with _fixed_point set to 0.

// Fixed const b(Fixed(5.05f) * Fixed(2));:

//     Multiplies 5.05 by 2 using the overloaded * operator, storing the result in b.

// Increment/Decrement Operations:

//     Demonstrates both pre-increment and post-increment behavior on a.

// Fixed::max(a, b):

//     Calls the static max function to print the larger of a and b.