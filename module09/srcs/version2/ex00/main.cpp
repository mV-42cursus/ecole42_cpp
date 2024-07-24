#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
	if (ac < 2) {
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	} else if (ac > 2) {
		std::cout << "wrong format : [./btc <file>] only.";
	}
	try {
		BitcoinExchange binance(av[1]);
		binance.dbMap();
		binance.execute();
	}	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
