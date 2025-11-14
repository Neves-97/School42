#include "../incs/Fixed.hpp"

  Fixed::Fixed() {

    _fixed_point = 0;
    std::cout << "Default constructor called" << std::endl;
  }

  Fixed::Fixed(const Fixed &obj) {

    _fixed_point = obj.getRawBits();
    std::cout << "Copy constructor called" << std::endl;
  }

  Fixed& Fixed::operator=(const Fixed &obj) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj) {
      _fixed_point = obj._fixed_point; 
    }
    return *this;
  }

  Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
  }

  int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return _fixed_point;
  }

  void Fixed::setRawBits(int const raw) {
    _fixed_point = raw;
  }

      // Default Constructor (Fixed::Fixed()):
      //     Initializes _fixed_point to 0.
      //     Prints "Default constructor called" to the console.
      // Copy Constructor (Fixed::Fixed(const Fixed &obj)):
      //     Initializes the new object with the value of another Fixed object by calling the getRawBits() method of the passed object.
      //     Prints "Copy constructor called" to the console.
      // Copy Assignment Operator (Fixed& Fixed::operator=(const Fixed &obj)):
      //     Checks if the current object is not the same as the passed object (to avoid self-assignment).
      //     If they are different, it copies the value of _fixed_point from the passed object.
      //     Prints "Copy assignment operator called" to the console.
      // Destructor (Fixed::~Fixed()):
      //     Prints "Destructor called" to the console when an object is destroyed.
      // Getter (getRawBits()):
      //     Returns the value of _fixed_point.
      //     Prints "getRawBits member function called" to the console.
      // Setter (setRawBits(int const raw)):
      //     Sets the value of _fixed_point to raw.
      //
      //      copy constructor and a copy assignment differ in that a copy constructor initializes uninitialized
      //memory, whereas the copy assignment operator must correctly deal with an object that has already
      //been constructed and may own resources.



// accessors are member functions that are used to access (or retrieve) the values of 
// private or protected member variables of a class. These functions are commonly known 
// as "getter" functions. Accessors allow you to retrieve the value of a data member 
//without directly accessing the member variable itself