#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

// Develop a class template Array that contains elements of type T and that implements the following behavior and functions:
template <typename T>
class Array
{
	private:
		T* elements;
		unsigned int n;
	public:
		// Construction with no parameter:	Creates an empty array.
		Array();
		~Array();
		// Construction with an unsigned int n as a parameter: Creates an array of n elements initialized by default
		// Tip: Try to compile int* a = new int(); then display *a
		Array(unsigned int n);

		// Construction by copy and assignment operator.
		// In both cases, modifying either the original array or its copy after copying mustn't affect the other array.
		/* ===============>>>>>>>>> "implement deep copy" */
		Array(const Array<T>& other);
		Array<T>& operator=(const Array<T>& other);
		T& operator[](unsigned int i);
		const T& operator[](unsigned int i) const;

		// accessors [getter || setter]
		unsigned int 	getN() const;
		void			setElements(T& value);

		// method || member functions
		void			rotateElements() const;
};

#include "Array.tpp"

#endif
