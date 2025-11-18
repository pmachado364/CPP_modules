#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {
	std::cout << "Default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n) {
	std::cout << "Parameterized constructor called" << std::endl;
	if(n == 0)
		_array = NULL;
	else
		_array = new T[n](); // having () insures the array members are default initiated
}

template <typename T>
Array<T>::Array(const Array& other) : _size(other._size) {
	std::cout << "Copy constructor called" << std::endl;
	if (_size == 0)
		_array = NULL;
	else {
		_array = new T[_size]();
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
}

template <typename T>
Array<T>::~Array() {
	std::cout << "Destructor called" << std::endl;
	if (_array)
		delete[] _array;
} //if _array is NULL, delete[] will do nothing

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	std::cout << "Assignment operator called" << std::endl;
	if(this != &other) {
		if (_array)
			delete[] _array;
		_size = other._size;
		if (_size == 0)
			_array = NULL;
		else {
			_array = new T[_size]();
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
		}
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return _size;
}