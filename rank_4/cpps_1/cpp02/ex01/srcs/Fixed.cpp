#include "../incs/Fixed.hpp"


Fixed::Fixed() {

	_fixed_point = 0;
	std::cout << "Default constructor calleed" << std::endl;
}

Fixed::Fixed(const Fixed &obj) {

	_fixed_point = obj._fixed_point;
	std::cout << "Copy construsctor" << std::endl;
}

Fixed::Fixed(const int value) {

	_fixed_point = value << _fractional_bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) {

	_fixed_point = roundf(value * (1 << _fractional_bits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &obj) {

	std::cout << "Copy assignment operator" << std::endl;
	if (this != &obj) {
		_fixed_point = obj._fixed_point;
	}
	return *this;
}

Fixed::~Fixed() {

	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {

	return _fixed_point;
}

void Fixed::setRawBits(int const raw) {

	_fixed_point = raw;
}

int Fixed::toInt() const {

	return _fixed_point >> _fractional_bits;
}

float Fixed::toFloat() const {

	return (float)_fixed_point / (1 << _fractional_bits);
}

std::ostream &operator<<(std::ostream &stream, const Fixed &obj) {
	stream << obj.toFloat();
	return stream;
}

// An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter.
// Default Constructor (Fixed::Fixed()):

//     Initializes _fixed_point to 0.

// Copy Constructor (Fixed::Fixed(const Fixed &obj)):

//     Initializes a new object with the _fixed_point value from another Fixed object.

// Constructor from int (Fixed::Fixed(const int value)):

//     Converts the integer value to a fixed-point representation by shifting the value left by _fractional_bits.

// Constructor from float (Fixed::Fixed(const float value)):

//     Converts the floating-point value to a fixed-point representation by multiplying by 2^_fractional_bits and rounding.

// Copy Assignment Operator (Fixed &Fixed::operator=(const Fixed &obj)):

//     Assigns the _fixed_point value from another Fixed object, checking for self-assignment.

// Destructor (Fixed::~Fixed()):

//     Outputs a message when a Fixed object is destroyed.

// Getter (getRawBits()):

//     Returns the raw fixed-point value.

// Setter (setRawBits(int const raw)):

//     Sets the raw fixed-point value.

// toInt() Method:

//     Converts the fixed-point value back to an integer by shifting it right by _fractional_bits.

// toFloat() Method:

//     Converts the fixed-point value back to a floating-point number.

// Overloaded operator<<:

//     Allows easy printing of Fixed objects as floating-point numbers.
