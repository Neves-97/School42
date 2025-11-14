#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer {

    public:

        ~Serializer();
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

    private:

        Serializer();
        Serializer(Serializer const &src);
        Serializer &operator=(Serializer const &src);
};

#endif


/*The class is made non-instantiable by making the constructor, copy constructor, and assignment operator private.
All methods are static, so they can be called without creating an object.
serialize() turns a Data* into a uintptr_t.
deserialize() does the reverse.*/