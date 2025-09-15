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
		Fixed(const Fixed& copy); // copy constructor

		Fixed(const int value); // int constructor
		Fixed(const float value); // float constructor

		Fixed& operator=(const Fixed& other); // copy assignment operator

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

};

std::ostream& operator<<(std::ostream& out, const Fixed& value);
#endif