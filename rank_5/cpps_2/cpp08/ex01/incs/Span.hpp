#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

class Span {
    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();
    
        void addNumber(int number);
    
        template <typename InputIterator>
        void addNumber(InputIterator begin, InputIterator end) {
            if (_numbers.size() + std::distance(begin, end) > _maxSize)
                throw std::runtime_error("Not enough space to add the range.");
            _numbers.insert(_numbers.end(), begin, end);
        }
    
        int shortestSpan() const;
        int longestSpan() const;
    
    private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

};

#endif
