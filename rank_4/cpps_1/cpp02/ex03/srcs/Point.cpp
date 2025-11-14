#include "../incs/Point.hpp"

// Default constructor
// A constructor in C++ is a special member function of a class that is automatically 
// called when an object of that class is created. It initializes the object, setting 
// up initial values for its data members.
Point::Point() {
    _x = 0;
    _y = 0;
}

// Parameterized constructor
// A parameterized constructor in C++ is a constructor that takes one or more arguments. 
// These arguments allow you to initialize an object with specific values at the time of its creation.
Point::Point(const float x, const float y) {
    _x = x;
    _y = y;
}

// Copy constructor
// A copy constructor in C++ is a special constructor that creates a new object 
// as a copy of an existing object. It takes a reference to an object of the same 
// class as its parameter and duplicates the values of the data members from the given object to the new one.
Point::Point(const Point &obj) {
    _x = obj._x;
    _y = obj._y;
}


// Copy assignment operator
// The copy assignment operator in C++ is a special operator (operator=) that is used 
// to copy the contents of one object to another existing object of the same class. 
// It assigns the values of the data members from the source object to the target object, 
// overwriting the target's current values.
Point &Point::operator=(const Point &obj) {
    if (this != &obj) {
        _x = obj.getX();
        _y = obj.getY();
    }
    return *this;
}

// Destructor
// A destructor in C++ is a special member function of a class that is automatically 
// called when an object of that class is destroyed. It is used to release resources, 
// such as memory or file handles, that the object may have acquired during its lifetime. 
// The destructor has the same name as the class, preceded by a tilde (~).
Point::~Point() {
    
}

// Getter for x
Fixed Point::getX() const {
    return _x;
}

// Getter for y
Fixed Point::getY() const {
    return _y;
}
