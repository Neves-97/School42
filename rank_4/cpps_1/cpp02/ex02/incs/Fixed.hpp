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

		bool operator>(const Fixed &obj) const;
    	bool operator<(const Fixed &obj) const;
    	bool operator>=(const Fixed &obj) const;
    	bool operator<=(const Fixed &obj) const;
    	bool operator==(const Fixed &obj) const;
    	bool operator!=(const Fixed &obj) const;

		Fixed operator+(const Fixed &obj) const;
    	Fixed operator-(const Fixed &obj) const;
    	Fixed operator*(const Fixed &obj) const;
    	Fixed operator/(const Fixed &obj) const;

		Fixed &operator++();        // Pre-increment
    	Fixed operator++(int);      // Post-increment
    	Fixed &operator--();        // Pre-decrement
    	Fixed operator--(int);      // Post-decrement

		static Fixed &min(Fixed &a, Fixed &b);
    	static const Fixed &min(const Fixed &a, const Fixed &b);
    	static Fixed &max(Fixed &a, Fixed &b);
    	static const Fixed &max(const Fixed &a, const Fixed &b);

	
	private:

		int _fixed_point;
		static const int _fractional_bits = 8;

};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif


// Comparison Operators

//     These operators allow comparing two Fixed objects using >, <, >=, <=, ==, and !=.

// Arithmetic Operators:

//     These operators allow performing arithmetic operations between two Fixed objects using +, -, *, and /.

// Increment/Decrement Operators:

//     The ++ and -- operators are overloaded to support both pre-increment/decrement (e.g., ++a) and post-increment/decrement (e.g., a++).

// Min/Max Functions:

//     These static methods return the minimum or maximum of two Fixed objects.