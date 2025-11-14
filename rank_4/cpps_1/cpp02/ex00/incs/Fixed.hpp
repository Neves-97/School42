#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

	public:

		Fixed();
		Fixed	(const Fixed &obj);
		Fixed	&operator=(const Fixed &obj);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		~Fixed();

	private:

		int _fixed_point;
		static const int _fracional_bits = 8;
};

#endif