#include <iostream>
#include <cstring>

int main(int argc, char *argv[]) {
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else {
        for (int i = 1; i < argc; ++i) {
            for (size_t j = 0; j < std::strlen(argv[i]); ++j)
                std::cout << (char)std::toupper(argv[i][j]);
        }
    }
    std::cout << std::endl;
    return 0;
}


// for (int i = 1; i < argc; ++i)
// This loop iterates over the command-line arguments, starting from index 1 (i = 1). 
// Index 0 (argv[0]) is the name of the program itself, so it skips that. It continues 
// until i is less than argc, the number of command-line arguments.

// Inner Loop:


// for (size_t j = 0; j < std::strlen(argv[i]); ++j)
// Inside the outer loop, there's an inner loop. This loop iterates over each character 
// of the current command-line argument, indexed by i. It starts from j = 0 and continues until j 
// is less than the length of the current argument, obtained using std::strlen(argv[i]).

// Character Conversion and Output:


// std::cout << (char)std::toupper(argv[i][j]);
// Inside the inner loop, each character of the current argument (argv[i][j]) is converted to uppercase 
// using std::toupper function from <cctype>. Then, the uppercase character is printed to the standard 
// output using std::cout.

// So, effectively, this nested loop structure allows the program to iterate over each character of each 
// command-line argument, convert it to uppercase, and print it out. This continues until all characters of 
// all arguments have been processed.





