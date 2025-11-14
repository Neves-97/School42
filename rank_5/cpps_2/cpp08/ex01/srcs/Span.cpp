#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) {
    *this = other;
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize)
        throw std::runtime_error("Span is full");
    _numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to perform operation, needs at least 2");

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan)
            minSpan = span;
    }

    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to perform operation, needs at least 2");

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return max - min;
}
