#include "Fixed.hpp"
#include <cmath>

// orthodox canonical
Fixed::Fixed() : fixed_point_value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed & other) : fixed_point_value(other.fixed_point_value) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixed_point_value = other.getRawBits();
	return *this;
}

// constructor
Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point_value = static_cast<int>(roundf(f * (1 << fractional_bits)));
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point_value = n << this->fractional_bits;
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

// method || member function
int Fixed::toInt() const {
	return this->fixed_point_value >> 8;
}

float Fixed::toFloat() const {
	return static_cast<float>(fixed_point_value) / (1 << fractional_bits);
}

// operator overloading
std::ostream& operator<<(std::ostream & out, const Fixed & f) {
	out << f.toFloat();
	return out;
}
