#include "../incs/Point.hpp"

Fixed::Fixed() {

	_fixed_point = 0;
}

Fixed::Fixed(const Fixed &obj) {

	_fixed_point = obj._fixed_point;
}

Fixed::Fixed(const int value) {

	_fixed_point = value << _fractional_bits;
}

Fixed::Fixed(const float value) {

	_fixed_point = roundf(value * (1 << _fractional_bits));
}

Fixed &Fixed::operator=(const Fixed &obj) {

	if (this != &obj) {
		_fixed_point = obj._fixed_point;
	}
	return *this;
}

Fixed::~Fixed() {

}

int Fixed::getRawBits() const {

	return _fixed_point;
}

void Fixed::setRawBits(int const raw) {

	_fixed_point = raw;
}

int Fixed::toInt() const {

	return _fixed_point >> _fractional_bits;
}

float Fixed::toFloat() const {

	return (float)_fixed_point / (1 << _fractional_bits);
}

bool Fixed::operator>(const Fixed &other) const {
    return _fixed_point > other._fixed_point;
}

bool Fixed::operator<(const Fixed &other) const {
    return _fixed_point < other._fixed_point;
}

bool Fixed::operator>=(const Fixed &other) const {
    return _fixed_point >= other._fixed_point;
}

bool Fixed::operator<=(const Fixed &other) const {
    return _fixed_point <= other._fixed_point;
}

bool Fixed::operator==(const Fixed &other) const {
    return _fixed_point == other._fixed_point;
}

bool Fixed::operator!=(const Fixed &other) const {
    return _fixed_point != other._fixed_point;
}

Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &obj) const {
	return Fixed(this->toFloat() / obj.toFloat());
}

Fixed &Fixed::operator++() {
    _fixed_point++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    _fixed_point++;
    return temp;
}

Fixed &Fixed::operator--() {
    _fixed_point--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    _fixed_point--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}


std::ostream &operator<<(std::ostream &out, const Fixed &value) {

	out << value.toFloat();
	return out;
}