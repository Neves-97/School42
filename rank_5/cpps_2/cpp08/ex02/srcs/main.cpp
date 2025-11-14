#include "MutantStack.hpp"
#include <iostream>
#include <string>

int main() {
    std::cout << "--- Basic int stack ---" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    // std::cout << "Top: " << mstack.top() << std::endl;

    mstack.pop();
    // std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Normal Iterator:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "Reverse Iterator:" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    while (rit != rite) {
        std::cout << *rit << std::endl;
        ++rit;
    }

    std::cout << "Const Iterator:" << std::endl;
    const MutantStack<int> const_stack = mstack;
    MutantStack<int>::const_iterator cit = const_stack.begin();
    MutantStack<int>::const_iterator cite = const_stack.end();
    while (cit != cite) {
        std::cout << *cit << std::endl;
        ++cit;
    }

    std::cout << "Reverse Const Iterator:" << std::endl;
    const MutantStack<int> rconst_stack = mstack;
    MutantStack<int>::const_reverse_iterator rcit = rconst_stack.rbegin();
    MutantStack<int>::const_reverse_iterator rcite = rconst_stack.rend();
    while (rcit != rcite) {
        std::cout << *rcit << std::endl;
        ++rcit;
}

    std::cout << "--- Testing copy constructor ---" << std::endl;
    MutantStack<int> copyStack(mstack);
    while (!copyStack.empty()) {
        std::cout << copyStack.top() << std::endl;
        copyStack.pop();
    }

    std::cout << "--- Testing assignment operator ---" << std::endl;
    MutantStack<int> assignStack;
    assignStack = mstack;
    while (!assignStack.empty()) {
        std::cout << assignStack.top() << std::endl;
        assignStack.pop();
    }

    std::cout << "--- Using MutantStack with strings ---" << std::endl;
    MutantStack<std::string> strStack;
    strStack.push("hello");
    strStack.push("world");
    for (MutantStack<std::string>::iterator sit = strStack.begin(); sit != strStack.end(); ++sit)
        std::cout << *sit << std::endl;

    return 0;
}
