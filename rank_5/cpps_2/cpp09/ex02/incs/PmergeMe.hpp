#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <deque>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <exception>
#include <sys/time.h>

class PmergeMe {
private:
    std::deque<int> _deque;
    std::deque<int> _deque_result;
    std::list<int> _list;
    std::list<int> _list_result;

public:
    PmergeMe(char **av);
    ~PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &copy);

    void display();
    void print_deque(const std::deque<int>& dq) const;
    void print_list() const;

    std::deque<int> fordJohnsonSortDeque(const std::deque<int>& dq);
    std::list<int> fordJohnsonSortList(const std::list<int>& lst);

private:
    // bool isInvalidChar(char c) const;
    // bool hasInvalidChars(const std::string& str);
    void insertBinary(std::deque<int>& dq, int value) const;
    void insertBinary(std::list<int>& lst, int value) const;
    std::deque<int> generateJacobsthal(int maxVal) const;
    std::list<int> lst_generateJacobsthal(int maxVal) const;
};

#endif
