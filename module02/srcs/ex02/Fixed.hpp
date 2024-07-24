#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	static const  int 	fractional_bits = 8;
	int 				fixed_point_value;
public:
	// orthodox canonical
	Fixed();
	~Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);

	// constructor
	Fixed(const int n);
	Fixed(const float f);

	// getter && setter
	int 	getRawBits() const;
	void 	setRawBits(int const raw);

	// method || member function
	float 	toFloat() const;
	int 	toInt() const;

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

	// operator overloading
	bool operator>(const Fixed& f) const;
	bool operator<(const Fixed& f) const;
	bool operator>=(const Fixed& f) const;
	bool operator<=(const Fixed& f) const;
	bool operator==(const Fixed& f) const;
	bool operator!=(const Fixed& f) const;

	Fixed operator+(const Fixed &f) const;
	Fixed operator-(const Fixed &f) const;
	Fixed operator*(const Fixed &f) const;
	Fixed operator/(const Fixed &f) const;

	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);
};

std::ostream& operator<<(std::ostream& out, const Fixed& f);

#endif