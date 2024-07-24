#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

BitcoinExchange::~BitcoinExchange() {
	if (inputFileStream.is_open())
		inputFileStream.close();
}

BitcoinExchange::BitcoinExchange(const std::string& inputFile) : inputFileStream(inputFile.c_str())
{
	if (inputFileStream) {
		;
	} else {
		throw (Error("Input file stream does not exist."));
	}
}

BitcoinExchange::BitcoinExchange::Error::Error(const std::string& errMsg) : _err_msg(errMsg) {}

const char* BitcoinExchange::Error::what() const throw() {
	return (_err_msg.c_str());
}

void BitcoinExchange::dbMap()
{
    std::ifstream file(DEFAULT_DB_FILE_DIRECTORY);
    std::string line;
    if (!file.is_open()) {
        throw(Error("Database could not be opened."));
    }

	std::getline(file, line);
	if (line != "date,exchange_rate") {
		file.close();
		throw (Error("Database contaminated."));
	}
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string key;
        double value;
        if (getline(ss, key, ',') && ss >> value) {
            dataBase[key] = value;
        }	else {
    		file.close();
			throw(Error("Error: Database contaminated."));
		}
    }
    file.close();

#ifdef DEBUG
	std::cout << GREEN;
	for (std::map<std::string, double>::const_iterator it = dataBase.begin(); it != dataBase.end(); ++it) {
		std::cout << it->first << ": " << it->second << std::endl;
	}
	std::cout << WHITE;
#endif
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void BitcoinExchange::isValidDate(const std::string& date) {
	std::istringstream 	dateStream(date);
	int 				year, month, day;
	char 				delimeter;
	if (date.length() != 11) {
		throw (Error("Error: bad input => " + date));
	}

	dateStream >> year >> delimeter >> month >> delimeter >> day;
	if (delimeter != '-') {
		throw (Error("Error: bad input => " + date));
	}


	if (year < 2009 || year > 2100) {
		throw (Error("Error: bad input => " + date));
	}
	if (month < 1 || month > 12) {
		throw (Error("Error: bad input => " + date));
	}
	int daysInMonth[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (day < 1 || day > daysInMonth[month - 1]) {
		throw (Error("Error: bad input => " + date));
	}
}

void  BitcoinExchange::isValidValue(const std::string& value) {
	std::istringstream 	iss(value);
    double 				num;

    if (!(iss >> num) || !iss.eof()) {
        throw (Error("Error: Invalid value."));
    }

    if (!(num >= 0 && num <= 1000)) {
        if (num < 0) {
			throw (Error("Error: not a positive number."));
		} else {
			throw (Error("Error: too large of a number."));
		}
    }
}

void BitcoinExchange::calculateBTC(std::string& date, std::string& value) {
	double closestValue = 0.0;

	std::map<std::string, double>::const_iterator it = dataBase.upper_bound(date);

	if (it == dataBase.begin()) {
		throw(Error("Error: No available date found."));
	}

	if (it != dataBase.begin()) {
		--it;
	}

	closestValue = it->second;

	std::istringstream	iss(value);
	double num;
    if (!(iss >> num) || !iss.eof()) {
        throw (Error("Error: Invalid value."));
    }

	std::cout << date << "=> ";
	std::cout << num << " = ";
	std::cout << num * closestValue << std::endl;
}

void BitcoinExchange::execute()
{
	// header 있는지 확인
	std::string line;
	std::getline(inputFileStream, line);

	if (line != "date | value")
		throw (Error("input file is invalid."));

	while (std::getline(inputFileStream, line))
	{
		std::istringstream iss(line);
		std::string date, value;
		std::getline(iss, date, '|');
		std::getline(iss, value);

		// date validation
		try {
			isValidDate(date);
			isValidValue(value);
			calculateBTC(date, value);
		} catch (BitcoinExchange::Error &e) {
			std::cout << e.what() << std::endl;
		}
	}
}
