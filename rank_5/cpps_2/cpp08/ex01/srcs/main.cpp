#include "Span.hpp"
#include <iostream>
#include <cstdlib>

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib> // for rand()
#include <ctime>   // for time()

int main() {
    try {
        // ✅ Normal test
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "sp shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "sp longest span: " << sp.longestSpan() << std::endl;

        // 🧨 Exceeding capacity
        Span sp1 = Span(2);
        sp1.addNumber(1);
        sp1.addNumber(2);
        sp1.addNumber(3); // Should throw
    } catch (std::exception& e) {
        std::cerr << "sp1 error: " << e.what() << std::endl;
    }

    try {
        // 🧨 shortestSpan with < 2 numbers
        Span sp2 = Span(1);
        sp2.addNumber(42);
        std::cout << "sp2 shortest span: " << sp2.shortestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cerr << "sp2 error: " << e.what() << std::endl;
    }

    try {
        // 🧨 longestSpan with < 2 numbers
        Span sp3 = Span(1);
        sp3.addNumber(99);
        std::cout << "sp3 longest span: " << sp3.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cerr << "sp3 error: " << e.what() << std::endl;
    }

    try {
        // ✅ Test with 10,000+ numbers
        std::srand(std::time(NULL));
        Span bigSpan(10000);
        for (int i = 0; i < 10000; ++i)
            bigSpan.addNumber(std::rand());
        std::cout << "bigSpan shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "bigSpan longest span: " << bigSpan.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cerr << "bigSpan error: " << e.what() << std::endl;
    }

    return 0;
}
