#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	// OCCF
	MutantStack() : std::stack<T> () {}
	~MutantStack() {};
	MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {}
	MutantStack<T>& operator=(const MutantStack<T>& other) {
		std::stack<T>::operator=(other);
		return (*this);
	}

	// iterator
    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }

	// reverse iterator
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }

	// const iterator
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    const_iterator cbegin() const { return this->c.begin(); }
    const_iterator cend() const { return this->c.end(); }

	// const reverse iterator
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator crbegin() const { return this->c.rbegin(); }
	const_reverse_iterator crend() const { return this->c.rend(); }
};

#endif
