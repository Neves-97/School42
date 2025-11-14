#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <string>

class ScalarConverter {

	public:

		~ScalarConverter();
		static void convert(std::string input);

	private:

		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
};

#endif