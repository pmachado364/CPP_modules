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

		Fixed& operator=(const Fixed& other);
		int getRawBits (void) const;
		void setRawBits (int const raw);

		//-----New fields for ex01-----//
		Fixed(const int);
		Fixed( const float);

		int toInt( void ) const;
		float toFloat( void ) const;

};

std::ostream& operator<<(std::ostream& out, const Fixed& value); //insertion operator nao faz parte da classe

#endif