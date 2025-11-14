#include "../incs/ScalarConverter.hpp"

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string input)
{
	try
    {
		int i;
        char c;
        std::istringstream iss(input);
        iss >> i;
        if (iss.fail())
        {
			if (input.length() == 1 && isprint(input[0]))
            {
				c = input[0];
                std::cout << "char: '" << c << "'" << std::endl;
            }
            else
			throw std::invalid_argument("invalid argument");
	}
	else if (i >= 32 && i <= 126)
	{
		c = static_cast<char>(i); // compile time cast int to char via ascii: 48 = 0 ...
		std::cout << "char: '" << c << "'" << std::endl;
	}
	else
	{
		std::cout << "char: Non displayable" << std::endl;
	}
}
catch (std::invalid_argument &) {
	std::cout << "char: impossible" << std::endl;
}


/*It tries to read an int from the input.
If that fails, maybe it's just a single printable character (like 'A'), so we cast that to char.
If it is a valid int, it checks whether it's a displayable ASCII char (32–126).
Else, says "Non displayable".
If it's none of the above, "char: impossible". */

// displays 32 to 126 on the characte rascii table

try
{
	int i;
	std::istringstream iss(input);
	iss >> i;
	if (iss.fail())
	{
		if (input.length() == 1 && isprint(input[0]))
		{
			i = static_cast<int>(input[0]);
			std::cout << "int: " << i << std::endl;
		}
		else
		throw std::invalid_argument("invalid argument");
}
else
std::cout << "int: " << i << std::endl;
}
catch (std::invalid_argument &)
{
	std::cout << "int: impossible" << std::endl;
}
catch (std::out_of_range &)
{
	std::cout << "int: out of range" << std::endl;
}

/*It again tries to read an int.
If it fails and it’s a single printable character, converts it to its ASCII int value.
Otherwise, prints the int.
Handles invalid_argument and out_of_range exceptions.*/

try
{
	float f;
	if (input == "nan" || input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff" || input == "nanf" || input == "inf" || input == "inff")
	{
		f = std::numeric_limits<float>::quiet_NaN();
	}
	else if (input == "+inf" || input == "+inff" || input == "inf" || input == "inff")
	{
		f = std::numeric_limits<float>::infinity();
	}
	else if (input == "-inf" || input == "-inff")
	{
		f = -std::numeric_limits<float>::infinity();
	}
	else
	{
		std::istringstream iss(input);
		iss >> f;
		if (iss.fail())
		{
			if (input.length() == 1 && isprint(input[0]))
			f = static_cast<float>(input[0]);
		else
		throw std::invalid_argument("invalid argument");
}
}
std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}
catch (std::invalid_argument &)
{
	std::cout << "float: invalid argument" << std::endl;
}
catch (std::out_of_range &)
{
	std::cout << "float: out of range" << std::endl;
}

/*Handles special cases like nan, inf, +inf, -inf.
Then tries to read a float value from the input.
If the input is a char, it casts to float.
If none of these, throws.
Prints float with 1 decimal (like 42.0f).*/

try
{
	double d;
	if (input == "nan" || input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff" || input == "nanf" || input == "inf" || input == "inff")	{
		d = std::numeric_limits<double>::quiet_NaN();
	}
	else if (input == "+inf" || input == "+inff" || input == "inf" || input == "inff")
	{
		d = std::numeric_limits<double>::infinity();
	}
	else if (input == "-inf" || input == "-inff")
	{
		d = -std::numeric_limits<double>::infinity();
	}
	else
	{
		std::istringstream iss(input);
		iss >> d;
		if (iss.fail())
		{
			if (input.length() == 1 && isprint(input[0]))
			d = static_cast<double>(input[0]);
		else
		throw std::invalid_argument("invalid argument");
}
}
std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
catch (std::invalid_argument &)
{
	std::cout << "double: invalid argument" << std::endl;
}
catch (std::out_of_range &)
{
	std::cout << "double: out of range" << std::endl;
}
}


/*Same logic as float, just with double.
nanf is accepted even though technically it’s a float; for compatibility.*/


/* this converts string input into its possible scalar types: 
scalar types are primitive objects which contain a single value 
and are not composed of other c++objects.
char int float double
*/

/*So, what this code is doing is:
Type	Strategy
char	Try to parse as int. If not, accept printable char. Handle ASCII printable range.
int	Try to parse as int. If not, cast from char.
float	Handle special cases (nanf, +inff, etc), then try parsing.
double	Same as float, but with double.

All results are printed, even if conversions fail.*/


/*void ScalarConverter::convert(std::string input)

    This defines a static member function (based on usual conventions) of a class ScalarConverter.

    The function takes one argument: a std::string input, which is the value to be converted.

try
{

    Start of a try block, which means the code inside may throw exceptions and will be caught by the corresponding catch.

    int i;
    char c;
    std::istringstream iss(input);

    Declares two variables: i for holding an integer, c for a character.

    iss is an input string stream created from the input string, used to parse the string into numbers.

    iss >> i;

    Attempts to extract an integer from the input string and store it in i.

    if (iss.fail())

    Checks if the stream extraction failed. This means the input could not be interpreted as an integer.

        if (input.length() == 1 && isprint(input[0]))

    If the input string is exactly one character long and that character is printable (like 'a', '7', '!', etc.):

            c = input[0];
            std::cout << "char: '" << c << "'" << std::endl;

    Then assign the character to c and print it wrapped in single quotes.

        else
            throw std::invalid_argument("invalid argument");

    If the input string is not a single printable character and not an int either, throw an exception.

    else if (i >= 32 && i <= 126)

    If the input was successfully converted to an int, check if the value falls within the range of printable ASCII characters (from space to ~).

        c = static_cast<char>(i);
        std::cout << "char: '" << c << "'" << std::endl;

    Cast the int to a char (compile-time cast) and print it.

    else
    {
        std::cout << "char: Non displayable" << std::endl;
    }

    If the int is not in the printable range (e.g., ASCII values like 10 for newline, or 127 for delete), say it's "Non displayable".

}
catch (std::invalid_argument &) {
    std::cout << "char: impossible" << std::endl;
}*/