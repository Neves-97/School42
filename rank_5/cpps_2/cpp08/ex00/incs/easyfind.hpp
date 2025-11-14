#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

#include <algorithm>
#include <iostream>
#include <exception>
#include <vector>
#include <list>

class DontExistException: public std::exception {
    
    public:

        virtual const char *what() const throw() {return "target not found"; }
};

template<typename T>

typename T::iterator easyfind(T &container, int number) {


   typename T::iterator it = std::find(container.begin(), container.end(), number);
   if (it == container.end())
       throw DontExistException();
   return it;
}
 
#endif