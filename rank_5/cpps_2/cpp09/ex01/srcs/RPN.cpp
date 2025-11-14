#include "RPN.hpp"
#include <sstream>
#include <iostream>
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(const RPN &other) {
    *this = other;
}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other)
        this->_stack = other._stack;
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string &token) const {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::processToken(const std::string &token) {
    if (token.length() == 1 && isdigit(token[0])) {
        _stack.push(token[0] - '0');
    } else if (isOperator(token)) {
        if (_stack.size() < 2)
            return false;

        int b = _stack.top(); _stack.pop();
        int a = _stack.top(); _stack.pop();

        int result = 0;
        if (token == "+")
            result = a + b;
        else if (token == "-")
            result = a - b;
        else if (token == "*")
            result = a * b;
        else if (token == "/") {
            if (b == 0)
                return false;
            result = a / b;
        }

        _stack.push(result);
    } else {
        return false;
    }
    return true;
}

void RPN::evaluate(const std::string &expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (!processToken(token)) {
            std::cerr << "Error" << std::endl;
            return;
        }
    }

    if (_stack.size() != 1) {
        std::cerr << "Error" << std::endl;
        return;
    }

    std::cout << _stack.top() << std::endl;
}
