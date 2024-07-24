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
	Fixed& operator=(const Fixed & other);

	// constructors
	Fixed(const int n);
	Fixed(const float f);

	// getter && setter
	int getRawBits() const;
	void setRawBits(int const raw);

	// method || member function
	float toFloat() const;
	int toInt() const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& other);

#endif