#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& out, const Fixed& value) {
	out << value.toFloat();
	return out;
}

// Assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
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