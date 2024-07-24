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

// Insertion Operator
std::ostream& operator<<(std::ostream& out, const Fixed& f)
{
	out << f.toFloat();
	return out;
}

// Comparison Operator overloading
bool Fixed::operator>(const Fixed& f) const { return this->getRawBits() > f.getRawBits(); }
bool Fixed::operator<(const Fixed& f) const { return this->getRawBits() < f.getRawBits(); }
bool Fixed::operator>=(const Fixed& f) const { return this->getRawBits() >= f.getRawBits(); }
bool Fixed::operator<=(const Fixed& f) const { return this->getRawBits() <= f.getRawBits(); }
bool Fixed::operator==(const Fixed &f) const { return this->getRawBits() == f.getRawBits(); }
bool Fixed::operator!=(const Fixed &f) const { return this->getRawBits() != f.getRawBits(); }

// Arithmetic Operator
Fixed Fixed::operator+(const Fixed& f) const
{
	Fixed res(this->toFloat() + f.toFloat());
	return res;
}

Fixed Fixed::operator-(const Fixed& f) const
{
	Fixed res(this->toFloat() - f.toFloat());
	return res;
}

Fixed Fixed::operator*(const Fixed& f) const
{
	Fixed res(this->toFloat() * f.toFloat());
	return res;
}

Fixed Fixed::operator/(const Fixed& f) const
{
	Fixed res(this->toFloat() / f.toFloat());
	
	return res;
}

// Postfix & Prefix Incrementation, Decremenation
Fixed& Fixed::operator--()
{
	this->fixed_point_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--(*this);
	return tmp;
}

Fixed& Fixed::operator++()
{
	this->fixed_point_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++(*this);
	return tmp;
}

// Method Functions
int Fixed::getRawBits() const {	return this->fixed_point_value; }
void Fixed::setRawBits(int const raw) {	this->fixed_point_value = raw; }
int Fixed::toInt() const { return this->fixed_point_value >> 8; }
float Fixed::toFloat() const { return static_cast<float>(fixed_point_value) / (1 << fractional_bits); }

Fixed& Fixed::min(Fixed& a, Fixed& b) { return ((a <= b) ? a : b); }
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return ((a <= b) ? a : b); }
Fixed& Fixed::max(Fixed& a, Fixed& b) { return ((a > b) ? a : b); }
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return ((a > b) ? a : b); }
