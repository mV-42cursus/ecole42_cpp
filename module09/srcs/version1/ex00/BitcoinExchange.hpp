#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <ctime>
#include <exception>
#include <map>
#include <iostream>
#define DEFAULT_DB_FILE_DIRECTORY "./data.csv"

#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define GREEN_BOLD "\033[1;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define DEF_COLOR "\033[0;39m"
#define LF "\e[1K\r"

class BitcoinExchange
{
private:
	std::ifstream inputFileStream;
	std::map<std::string, double> dataBase;

private:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);

public:
	BitcoinExchange(const std::string& inputFile);
	~BitcoinExchange();

	void dbMap();
	void execute();
	void calculateBTC(std::string& date, std::string& value);

public:
	class Error : public std::exception
	{
	private:
		std::string _err_msg;
	public:
		Error(const std::string& errMsg);
		~Error() throw() {};
		const char* what() const throw();
	};
};

#endif