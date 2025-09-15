#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0) {
}
Fixed::Fixed (const int num) {
	fixedPointValue = num << fractionalBits;
}

Fixed::Fixed (const float num) {
	fixedPointValue = roundf(num * (1 << fractionalBits));
}

Fixed::~Fixed() {
}

Fixed::Fixed(const Fixed& copy) {
	fixedPointValue = copy.getRawBits();
}

int Fixed::getRawBits(void) const {
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

/* ------------ OPERATORS ------------ */

std::ostream& operator<<(std::ostream& out, const Fixed& value) {
	out << value.toFloat();
	return out;
}

// Assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		fixedPointValue = other.getRawBits();
	return *this;
}

// Arithmetic operators : + - * /

Fixed Fixed::operator+(const Fixed& other) const {
	return Fixed(this->toFloat() + other.toFloat());
}
Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed(this->toFloat() - other.toFloat());
}
Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed& other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

//Comparison operators : > < >= <= == !=
bool Fixed::operator>(const Fixed& other) const {
	return this->fixedPointValue > other.fixedPointValue;
}
bool Fixed::operator<(const Fixed& other) const {
	return this->fixedPointValue < other.fixedPointValue;
}
bool Fixed::operator>=(const Fixed& other) const {
	return this->fixedPointValue >= other.fixedPointValue;
}
bool Fixed::operator<=(const Fixed& other) const {
	return this->fixedPointValue <= other.fixedPointValue;
}
bool Fixed::operator==(const Fixed& other) const {
	return this->fixedPointValue == other.fixedPointValue;
}
bool Fixed::operator!=(const Fixed& other) const {
	return this->fixedPointValue != other.fixedPointValue;
}

// Increment / Decrement operators : ++ -- (prefix and postfix)

Fixed& Fixed::operator++() {
	fixedPointValue++;
	return *this; //incrementamos e retornamos o valor incrementado
}
Fixed Fixed::operator++(int) {
	Fixed old(*this); //copia do valor atual
	fixedPointValue++; //incrementa o valor atual
	return old; //retorna a copia com o valor antigo, o valor atual ja foi incrementado
}
Fixed& Fixed::operator--() {
	fixedPointValue--;
	return *this; //decrementamos e retornamos o valor decrementado
}
Fixed Fixed::operator--(int) {
	Fixed old(*this); //copia do valor atual
	fixedPointValue--; //decrementa o valor atual
	return old; //retorna a copia com o valor antigo, o valor atual ja foi decrementado
}