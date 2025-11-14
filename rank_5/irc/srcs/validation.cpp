#include "../incs/validation.hpp"

// PORT VALIDATION
bool validPort(const char *portStr) {
    char *last;
    long port = std::strtol(portStr, &last, 10);

    // 65535 because that is the total number of ports.
    // ports below 1024 need sudo to bind
    if (port <= 0 || port > 65535 || *last != '\0') { 
        std::cerr << "Invalid port number: " << portStr << std::endl;
        return false;
    }

    std::cout << "Valid Port: " << port << std::endl;
    return true;
}

// PASSWORD VALIDATION
bool hasNumber(const std::string &string) {
    for (size_t i = 0; i < string.length(); ++i) {
        if (std::isdigit(string[i])) {
            return true;
        }
    }
    return false;
}

// SPECIAL CHARACTER
bool hasSpecial(const std::string &string) {
    for (size_t i = 0; i < string.length(); ++i) {
        if (!std::isalnum(string[i])) {
            return true;
        }
    }
    return false;
}

// VALID CONDITIONS

bool validPassword(const std::string &password) {
    if (password.empty()) {
        std::cerr << "Password Error: Password can't be empty" << std::endl;
        return false;
    }

    if (password.length() < 6 || password.length() > 10) {
        std::cerr << "Password Error: Password must have between 6 and 10 characters" << std::endl;
        return false;
    }

    if (!hasNumber(password) || !hasSpecial(password)) {
        std::cerr << "Password Error: Password must have at least one number and one special character" << std::endl;
        return false;
    }
    
    std::cout << "Password is valid!" << std::endl;
    return true;
}