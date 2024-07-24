#include "Fixed.hpp"

// orthodox canonical
Fixed::Fixed() : fixed_point_value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : fixed_point_value(other.fixed_point_value) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixed_point_value = other.getRawBits();
	return *this;
}

// getter && setter
int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixed_point_value;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed_point_value = raw;
}
