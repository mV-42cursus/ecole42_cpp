#include "Array.hpp"
#include <cstddef>
#include <typeinfo>
#include <iostream>

template <typename T>
Array<T>::Array()
	: elements(NULL)
	, n(0)
	{
		std::cout << "Creating an array of type: " << typeid(T).name() << std::endl;
		std::cout << "[Array] Default Constructor called." << std::endl;
	}

template <typename T>
Array<T>::~Array()
{
	delete[] this->elements;
}


template <typename T>
Array<T>::Array(unsigned int n)
	: elements(new T[n])
	, n(n) 
	{
		std::cout << "Creating an array of type: " << typeid(T).name() << std::endl;
		std::cout << "[Array] Parameterized Constructor called." << std::endl;
	}

template <typename T>
Array<T>::Array(const Array<T>& other)
{
	std::cout << "Copy Constructor called." << std::endl;
	if (other.elements == NULL) {
		this->elements = NULL;
		this->n = 0;
	}
	else {
		this->elements = new T[other.n];
		this->n = other.n;
		for (unsigned int i = 0; i < this->n; i++)
			this->elements[i] = other.elements[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this == &other)
		return (*this);
	else
	{
        delete[] this->elements;

        this->n = other.n;
        this->elements = new T[this->n];
        for (unsigned int i = 0; i < this->n; i++)
            this->elements[i] = other.elements[i];
    }
    return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int i) {
	if (i >= this->getN())
		throw std::exception();
	return (this->elements[i]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const {
	if (i >= this->getN())
		throw std::exception();
	return (this->elements[i]);
}

// accessors [getter || setter]
template <typename T>
unsigned int Array<T>::getN() const {
	return (this->n);
}

template <typename T>
void Array<T>::setElements(T& value) {
	for (unsigned int i = 0; i < this->getN(); i++)
		this->elements[i] = value;
}

// method || member functions
template <typename T>
void Array<T>::rotateElements() const {
	for (unsigned int i = 0; i < this->getN(); i++)
		std::cout << "[" << &this->elements[i] << "::" << this->elements[i] << "]" << std::endl;
	std::cout << std::endl;
}
