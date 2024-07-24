#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T* array, size_t const length, F function) {
	for (size_t i = 0; i < length; i++) {
		function(array[i]);
	}
}

template <typename T>
void pritTemplate(const T &arg) {
	std::cout << arg << std::endl;
}

#endif