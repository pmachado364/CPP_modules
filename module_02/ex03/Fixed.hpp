#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int fixedPointValue;
		static const int fractionalBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& copy);
		Fixed(const int);
		Fixed(const float);

		//assignment operator
		Fixed& operator=(const Fixed& other);

		//arithmetic operators
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;
		
		//comparison operators
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		//increment/decrement operators
		Fixed& operator++(); //prefix
		Fixed operator++(int); //postfix
		Fixed& operator--(); //prefix
		Fixed operator--(int); //postfix

		int getRawBits (void) const;
		void setRawBits (int const raw);
		int toInt( void ) const;
		float toFloat( void ) const;

		static Fixed& min (Fixed& a, Fixed& b);
		static const Fixed& min (const Fixed& a, const Fixed& b);
		static Fixed& max (Fixed& a, Fixed& b);
		static const Fixed& max (const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& out, const Fixed& value); //insertion operator nao faz parte da classe

#endif