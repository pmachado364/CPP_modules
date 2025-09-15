#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
	std::cout << "Copy constructor called" << std::endl;
	fixedPointValue = copy.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		fixedPointValue = other.getRawBits();
	return *this;
}

int Fixed::getRawBits (void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return fixedPointValue;
}

void Fixed::setRawBits (int const raw) {
	fixedPointValue = raw;
}


//-----New fields for ex01-----//

Fixed::Fixed (const int num) {
	std::cout << "Int constructor called" << std::endl;
	fixedPointValue = num << fractionalBits;
}

Fixed::Fixed (const float num) {
	std::cout << "Float constructor called" << std::endl;
	fixedPointValue = roundf(num * (1 << fractionalBits));
}

int Fixed::toInt( void ) const {
	return fixedPointValue >> fractionalBits;
}
float Fixed::toFloat( void ) const {
	return (float)fixedPointValue / (1 << fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& value) {
	out << value.toFloat();
	return out;
}