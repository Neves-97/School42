#include "../incs/Serializer.hpp"

int main() {
    // Creating Data objects with different content types
    Data *data1 = new Data;
    Data *data2 = new Data;
    Data *data3 = new Data;

    // Different string contents
    data1->content = "Roxanne";
    data2->content = "Tonight";
    data3->content = "Yup yup";

    // Serializing and deserializing the first object
    uintptr_t serial1 = Serializer::serialize(data1);
    Data *deserial1 = Serializer::deserialize(serial1);
    std::cout << "Serialized Data 1: " << serial1 << std::endl;
    std::cout << "Deserialized Data 1 Content: " << deserial1->content << std::endl;

    // Serializing and deserializing the second object
    uintptr_t serial2 = Serializer::serialize(data2);
    Data *deserial2 = Serializer::deserialize(serial2);
    std::cout << "Serialized Data 2: " << serial2 << std::endl;
    std::cout << "Deserialized Data 2 Content: " << deserial2->content << std::endl;

    // Serializing and deserializing the third object
    uintptr_t serial3 = Serializer::serialize(data3);
    Data *deserial3 = Serializer::deserialize(serial3);
    std::cout << "Serialized Data 3: " << serial3 << std::endl;
    std::cout << "Deserialized Data 3 Content: " << deserial3->content << std::endl;

    // Memory address checks
    std::cout << "Memory address check for Data 1:\n    |Original: " << data1 << "\n    |Deserialized: " << deserial1 << std::endl;
    std::cout << "Memory address check for Data 2:\n    |Original: " << data2 << "\n    |Deserialized: " << deserial2 << std::endl;
    std::cout << "Memory address check for Data 3:\n    |Original: " << data3 << "\n    |Deserialized: " << deserial3 << std::endl;

    delete data1;
    delete data2;
    delete data3;

    return 0;
}


// The serialized values (e.g., 97319663612592, 97319663612640, 97319663612688) represent the memory 
// addresses where the original Data objects were stored. Each serialized value should be unique for each 
// object, as seen in your output.

// Each deserialized content (e.g., "Hello, World!", "Serialization Test", "Another Test String") matches the 
// original content assigned to each Data object, confirming that the serialization and deserialization 
// processes are working correctly.

// The memory address checks confirm that the original and deserialized Data objects point to the same memory 
// locations (e.g., 0x5882fffab2b0 for Data 1, 0x5882fffab2e0 for Data 2, etc.). This is crucial because 
// it demonstrates that the deserialization process correctly restored the pointer to the original object.





/*Data *data1 = new Data;
data1->content = "Roxanne";

    You create three dynamic Data objects with different string content.

🔁 Serialization & Deserialization

uintptr_t serial1 = Serializer::serialize(data1);
Data *deserial1 = Serializer::deserialize(serial1);

Convert the pointer to an integer (serial1), then back into a pointer (deserial1).
You print the serialized value (an address as an integer) and check if the content matches.

✅ Address Check

std::cout << "Original: " << data1 << "\nDeserialized: " << deserial1 << std::endl;
This confirms that data1 and deserial1 point to the same memory location.

🧹 Memory Cleanup

delete data1;
delete data2;
delete data3;

    Clean up to avoid memory leaks.*/