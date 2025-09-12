#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>


class Fixed {
	private:
		int fixedPointValue; //int para armazenar o fixed point de cada objecto
		static const int fractionalBits = 8; //numero de fractional bits para a classe Fixed
	public:
		Fixed(); //default
		~Fixed(); //destructor
		Fixed(const Fixed& copy); //copy constructor
		Fixed& operator=(const Fixed& other); //copy assignment operator

		int getRawBits ( void ) const; //retorna o valor do fixed point
		void setRawBits ( int const raw ); //define o valor do fixed point
};

#endif