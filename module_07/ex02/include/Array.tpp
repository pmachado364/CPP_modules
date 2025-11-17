#include "Array.hpp"

template <class T>
Array<T>::Array() : data(NULL), n(0) {
}

template <class T>
Array<T>::Array(unsigned int n) : data(new T[n]()), n(n) {
}

template <class T>
Array<T>::Array(const Array<T>& other) : data(new T[other.n]()), n(other.n) {
	for (unsigned int i = 0; i < n; i++) {
		data[i] = other.data[i];
	}
}

template <class T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	if (this != &other) {
		delete[] data;
		n = other.n;
		data = new T[n]();
		for (unsigned int i = 0; i < n; i++) {
			data[i] = other.data[i];
		}
	}
	return *this;
}

template <class T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= n) {
		throw std::out_of_range("Index out of bounds");
	}
	return data[index];
}

template <class T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= n) {
		throw std::out_of_range("out of bounds");
	}
	return data[index];
}

template <class T>
Array<T>::~Array() {
	delete[] data;
}

template <class T>
unsigned int Array<T>::size() const {
	return n;
}