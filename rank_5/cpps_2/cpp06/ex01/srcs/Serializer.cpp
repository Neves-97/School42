#include "../incs/Serializer.hpp"

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}



/*Constructors/destructors are defined but do nothing.
reinterpret_cast<uintptr_t>(ptr): converts the pointer into an integer value.
reinterpret_cast<Data*>(raw): converts the integer back into a pointer.*/

/*Serialization: Turning a pointer into an integer value (uintptr_t) so it can be stored/transmitted.
Deserialization: Converting that integer back to the original pointer type (Data*).
uintptr_t: An unsigned integer type that is guaranteed to be able to hold a pointer (from <stdint.h>).*/


/*uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

    This converts a pointer (Data*) into an integer type.
    uintptr_t is an unsigned integer type guaranteed to hold a pointer (from <cstdint>).
    reinterpret_cast just reinterprets the bits of the pointer as an integer.

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

    This converts an integer back into a pointer (Data*).
    It's the reverse operation of serialize().
    No data is changed; only the type.

*/