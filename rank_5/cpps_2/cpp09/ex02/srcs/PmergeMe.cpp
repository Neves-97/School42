#include "PmergeMe.hpp"

bool isInvalidChar(char c) {
    return !std::isdigit(c) && c != ' ';
}

bool hasInvalidChars(const std::string& str) {
    return std::find_if(str.begin(), str.end(), isInvalidChar) != str.end();
}


PmergeMe::PmergeMe(char **av) {

    for (size_t i = 1; av[i]; ++i) {
        if (hasInvalidChars(av[i]))
            throw std::runtime_error("Error: Invalid character in input");

        int value = std::atoi(av[i]);
        if (value < 0)
            throw std::runtime_error("Error: Negative value encountered");

        if (std::find(_deque.begin(), _deque.end(), value) == _deque.end()) {
            _deque.push_back(value);
        } else {
            std::cout << "\033[1;31mDuplicate Detected: Action Ignored\033[0m" << std::endl;
        }

        if (std::find(_list.begin(), _list.end(), value) == _list.end()) {
            _list.push_back(value);
        } else {
            std::cout << "\033[1;31mDuplicate Detected: Action Ignored\033[0m" << std::endl;
        }
    }
}

PmergeMe::~PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe& other)
    : _deque(other._deque),
      _deque_result(other._deque_result),
      _list(other._list),
      _list_result(other._list_result) 
{
}


PmergeMe& PmergeMe::operator=(const PmergeMe& copy) {
    std::cout << "PmergeMe Assignment Operator" << std::endl;
    if (this != &copy) {
        _list = copy._list;
        _deque = copy._deque;
        _list_result = copy._list_result;
        _deque_result = copy._deque_result;
    }
    return *this;
}

void PmergeMe::print_deque(const std::deque<int>& dq) const {
    for (std::deque<int>::const_iterator it = dq.begin(); it != dq.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::print_list() const {
    for (std::list<int>::const_iterator it = _list.begin(); it != _list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::insertBinary(std::deque<int>& dq, int value) const {
    std::deque<int>::iterator it = std::lower_bound(dq.begin(), dq.end(), value);
    dq.insert(it, value);
}

void PmergeMe::insertBinary(std::list<int>& lst, int value) const {
    std::list<int>::iterator it = std::lower_bound(lst.begin(), lst.end(), value);
    lst.insert(it, value);
}

std::deque<int> PmergeMe::generateJacobsthal(int maxVal) const {
    std::deque<int> seq;
    seq.push_back(0);
    seq.push_back(1);

    while (1) {
        int prox = seq[seq.size() - 1] + 2 * seq[seq.size() - 2];
        if (prox > maxVal)
            break;
        seq.push_back(prox);
    }
    return seq;
}

std::list<int> PmergeMe::lst_generateJacobsthal(int maxVal) const {
    std::list<int> seq;
    seq.push_back(0);
    seq.push_back(1);

    std::list<int>::iterator it1 = seq.begin();
    std::list<int>::iterator it2 = ++seq.begin();

    while (1) {
        int prox = *it2 + 2 * *it1;
        if (prox > maxVal)
            break;
        seq.push_back(prox);
        it1 = seq.end();
        --it1;
        --it1;
        it2 = seq.end();
        --it2;
    }
    return seq;
}

std::deque<int> PmergeMe::fordJohnsonSortDeque(const std::deque<int>& dq) {
    size_t n = dq.size();
    if (n < 1) return dq;

    std::deque<int> bigger, smaller;

    for (size_t i = 0; i + 1 < n; i += 2) {
        if (dq[i] < dq[i + 1]) {
            smaller.push_back(dq[i]);
            bigger.push_back(dq[i + 1]);
        } else {
            smaller.push_back(dq[i + 1]);
            bigger.push_back(dq[i]);
        }
    }

    if (n % 2 != 0)
        smaller.push_back(dq[n - 1]);

    std::deque<int> order_deq = fordJohnsonSortDeque(bigger);
    std::deque<int> result;

    if (!bigger.empty()) result.push_back(order_deq[0]);
    if (!smaller.empty()) insertBinary(result, smaller[0]);

    for (size_t i = 1; i < order_deq.size(); ++i)
        insertBinary(result, order_deq[i]);

    std::deque<int> insertionOrder = generateJacobsthal(smaller.size() - 1);
    std::deque<bool> inserted(smaller.size(), false);
    inserted[0] = true;

    for (size_t i = 0; i < insertionOrder.size(); ++i) {
        unsigned int idx = insertionOrder[i];
        if (idx < smaller.size() && !inserted[idx]) {
            insertBinary(result, smaller[idx]);
            inserted[idx] = true;
        }
    }

    for (size_t i = 0; i < smaller.size(); ++i) {
        if (!inserted[i])
            insertBinary(result, smaller[i]);
    }
    return result;
}

std::list<int> PmergeMe::fordJohnsonSortList(const std::list<int>& lst) {
    size_t n = lst.size();
    if (n < 1) return lst;

    std::list<int> bigger, smaller;

    std::list<int>::const_iterator it = lst.begin();
    for (size_t i = 0; i + 1 < n; i += 2, std::advance(it, 2)) {
        std::list<int>::const_iterator next_it = ++it;
        --it;
        if (*it < *next_it) {
            smaller.push_back(*it);
            bigger.push_back(*next_it);
        } else {
            bigger.push_back(*it);
            smaller.push_back(*next_it);
        }
    }

    if (n % 2 != 0)
        smaller.push_back(*it);

    std::list<int> order_lst = fordJohnsonSortList(bigger);
    std::list<int> result;

    if (!bigger.empty()) result.push_back(order_lst.front());
    if (!smaller.empty()) insertBinary(result, smaller.front());

    std::list<int>::const_iterator order_it = ++order_lst.begin();
    for (; order_it != order_lst.end(); ++order_it)
        insertBinary(result, *order_it);

    std::list<int> insertionOrder = lst_generateJacobsthal(smaller.size() - 1);
    std::deque<bool> inserted(smaller.size(), false);
    inserted.front() = true;

    std::list<int>::iterator order_idx_it = insertionOrder.begin();
    for (; order_idx_it != insertionOrder.end(); ++order_idx_it) {
        unsigned int idx = *order_idx_it;
        if (idx < smaller.size() && !inserted[idx]) {
            std::list<int>::iterator sm_it = smaller.begin();
            std::advance(sm_it, idx);
            insertBinary(result, *sm_it);
            inserted[idx] = true;
        }
    }

    std::list<int>::iterator sm_it = smaller.begin();
    for (size_t i = 0; i < smaller.size(); ++i, ++sm_it) {
        if (!inserted[i])
            insertBinary(result, *sm_it);
    }
    return result;
}

void PmergeMe::display() {
    struct timeval start, end;

    std::cout << "Before: ";
    std::cout << "\033[1;34mDeque\033[0m ";
    print_deque(_deque);

    gettimeofday(&start, NULL);
    _deque_result = fordJohnsonSortDeque(_deque);
    gettimeofday(&end, NULL);

    std::cout << "After: ";
    std::cout << "\033[1;34mDeque\033[0m ";
    print_deque(_deque_result);

    std::cout << "Time to sort a range of " << _deque.size() << " elements with std::deque: ";
    std::cout << ((end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec)) << " microseconds" << std::endl;

    // std::cout << "Before: ";
    // std::cout << "\033[1;32mList\033[0m ";
    // print_list();

    gettimeofday(&start, NULL);
    _list_result = fordJohnsonSortList(_list);
    gettimeofday(&end, NULL);

    // std::cout << "After: ";
    // std::cout << "\033[1;32mList\033[0m ";
    // print_list();

    std::cout << "Time to sort a range of " << _list.size() << " elements with std::list: ";
    std::cout << ((end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec)) << " microseconds" << std::endl;
}
