#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm> // std::find
#include <exception> // std::exception

template <typename T>
int easyfind(T& container, int toFind) {
	typename T::iterator it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end()) {
		throw std::exception();
	}
	return *it;
}

#endif
