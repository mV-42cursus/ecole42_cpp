#include <iostream>
#include "Fixed.hpp"

#include <iostream>
int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "============================================" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	std::cout << "================= [MAX] ====================" << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "=============== [PreFix] ===================" << std::endl;
	Fixed d(10.120398019238f);
	Fixed e = ++d;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	std::cout << "=============== [PostFix] ==================" << std::endl;
	Fixed d2(10.120398019238f);
	Fixed e2 = d2++;
	std::cout << d2 << std::endl;
	std::cout << e2 << std::endl;
	std::cout << "============================================" << std::endl;

	return 0;
}
