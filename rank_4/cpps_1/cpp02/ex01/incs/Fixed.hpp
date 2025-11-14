#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

	public:

		Fixed();
		Fixed(const Fixed &obj);
		Fixed &operator=(const Fixed &obj);
		~Fixed();
		Fixed(const int value);
		Fixed(const float value);
		
		float	toFloat() const;
		int		toInt() const;
		int		getRawBits() const;
		void	setRawBits(int const raw);

	
	private:

		int _fixed_point;
		static const int _fractional_bits = 8;

};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif

// New Constructors:

//     Fixed(const int value): Constructs a Fixed object from an integer.
//     Fixed(const float value): Constructs a Fixed object from a floating-point number.

// New Methods:

//     float toFloat() const: Converts the fixed-point number to a floating-point number.
//     int toInt() const: Converts the fixed-point number to an integer.

// Overloaded operator<<:

//     Overloads the << operator to allow easy printing of Fixed objects as floating-point numbers.