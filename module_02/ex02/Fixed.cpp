#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed (const int num) {
	std::cout << "Int constructor called" << std::endl;
	fixedPointValue = num << fractionalBits;
}

Fixed::Fixed (const float num) {
	std::cout << "Float constructor called" << std::endl;
	fixedPointValue = roundf(num * (1 << fractionalBits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
	std::cout << "Copy constructor called" << std::endl;
	fixedPointValue = copy.getRawBits();
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	fixedPointValue = raw;
}

int Fixed::toInt( void ) const {
	return fixedPointValue >> fractionalBits;
}
float Fixed::toFloat( void ) const {
	return (float)fixedPointValue / (1 << fractionalBits);
}

// Min and Max functions
Fixed& Fixed::min (Fixed& a, Fixed& b) {
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::min (const Fixed& a, const Fixed& b) {
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max (Fixed& a, Fixed& b) {
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::max (const Fixed& a, const Fixed& b) {
	if (a > b)
		return a;
	return b;
}