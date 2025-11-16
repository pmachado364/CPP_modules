#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename Func>
void iter(T* array, const unsigned int length, Func func_pointer) {
	for (unsigned int i = 0; i < length; i++) {
		func_pointer(array[i]);
	}
}

#endif