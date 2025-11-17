#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {
	private:
		T* data;
		unsigned int n;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);

		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;

		~Array();
		unsigned int size() const;
};
#endif