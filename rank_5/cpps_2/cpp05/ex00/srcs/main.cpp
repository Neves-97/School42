#include "../incs/Bureaucrat.hpp"

// int main() {

//     try {

//         Bureaucrat x("yo", 149);
//         std::cout << x << std::endl;
//     }
//     catch (std::exception &err) {std::cerr << err.what() << std::endl;}
//     try {

//         Bureaucrat a("tommy", 1);
//         std::cout << a << std::endl;
//     }
//     catch (std::exception &err) {std::cerr << err.what() << std::endl;}
//     try {

//         Bureaucrat h("callme", 10000000);
//         std::cout << h << std::endl;
//     }
//     catch (std::exception &err) {std::cerr << err.what() << std::endl;}
//     try {

//         Bureaucrat b("shallme", -1111);
//         std::cout << b << std::endl;
//     }
//     catch (std::exception &err) {std::cerr << err.what() << std::endl;}
//     try {

//         Bureaucrat c("G", 50);
//         std::cout << c << std::endl;
//     }
//     catch (std::exception &err) {std::cerr << err.what() << std::endl;}
//     try {

//         Bureaucrat d("Trav", 0);
//         std::cout << d << std::endl;
//     }
//     catch (std::exception &err) {std::cerr << err.what() << std::endl;}
//     try {

//         Bureaucrat e("batthy", 200);
//         std::cout << e << std::endl;
//     }
//     catch (std::exception &err) {std::cerr << err.what() << std::endl;}
//     try {

//         Bureaucrat f("lil", 41);
//         std::cout << f << std::endl;
//     }
//     catch (std::exception &err) {std::cerr << err.what() << std::endl;}
//     try {

//         Bureaucrat g("joca", 7);
//         std::cout << g << std::endl;
//     }
//     catch (std::exception &err) {std::cerr << err.what() << std::endl;}
// }

// int main() {
//     try {
//         Bureaucrat x("yo", 149);
//         std::cout << x << std::endl;
//     }
//     catch (std::exception &e) { // Catch exception as std::exception &e
//         std::cerr << e.what() << std::endl;
//     }

//     try {
//         Bureaucrat a("tommy", 1);
//         std::cout << a << std::endl;
//     }
//     catch (std::exception &e) {
//         std::cerr << e.what() << std::endl;
//     }

//     try {
//         Bureaucrat h("callme", 10000000);
//         std::cout << h << std::endl;
//     }
//     catch (std::exception &e) {
//         std::cerr << e.what() << std::endl;
//     }

//     try {
//         Bureaucrat b("shallme", -1111);
//         std::cout << b << std::endl;
//     }
//     catch (std::exception &e) {
//         std::cerr << e.what() << std::endl;
//     }

//     try {
//         Bureaucrat c("G", 50);
//         std::cout << c << std::endl;
//     }
//     catch (std::exception &e) {
//         std::cerr << e.what() << std::endl;
//     }

//     try {
//         Bureaucrat d("Trav", 0);
//         std::cout << d << std::endl;
//     }
//     catch (std::exception &e) {
//         std::cerr << e.what() << std::endl;
//     }

//     try {
//         Bureaucrat e("batthy", 200);
//         std::cout << e << std::endl;
//     }
//     catch (std::exception &e) {
//         std::cerr << e.what() << std::endl;
//     }

//     try {
//         Bureaucrat f("lil", 41);
//         std::cout << f << std::endl;
//     }
//     catch (std::exception &e) {
//         std::cerr << e.what() << std::endl;
//     }

//     try {
//         Bureaucrat g("joca", 7);
//         std::cout << g << std::endl;
//     }
//     catch (std::exception &e) {
//         std::cerr << e.what() << std::endl;
//     }

//     return 0;
// }


int main() {

    try {
        Bureaucrat x("yo", 149);
        std::cout << x << std::endl;
    }
    catch (std::exception &e) { // Catch exception as std::exception &e
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat a("tommy", 1);
        std::cout << a << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat h("callme", 10000000);
        std::cout << h << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b("shallme", 3);
        std::cout << b << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat c("G", 50);
        std::cout << c << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat d("Trav", 0);
        std::cout << d << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        Bureaucrat x("yo", 2);
        std::cout << x << std::endl;

        x.incrementGrade(); // Should be fine, grade becomes 1
        std::cout << x << std::endl;

        x.incrementGrade(); // Should throw GradeTooHighException (grade < 1)
        std::cout << x << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        Bureaucrat a("tommy", 149);
        std::cout << a << std::endl;

        a.decrementGrade(); // Should be fine, grade becomes 150
        std::cout << a << std::endl;

        a.decrementGrade(); // Should throw GradeTooLowException (grade > 150)
        std::cout << a << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
