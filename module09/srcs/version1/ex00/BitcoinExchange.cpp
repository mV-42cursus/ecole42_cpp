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
	// Just for demonstration, printing the map
	for (std::map<std::string, double>::const_iterator it = dataBase.begin(); it != dataBase.end(); ++it) {
		std::cout << it->first << ": " << it->second << std::endl;
	}
	std::cout << WHITE;
#endif
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(const std::string& date) {
	std::istringstream 	dateStream(date);
	int 				year, month, day;
	char 				delimiter;

	dateStream >> year >> delimiter >> month >> delimiter >> day;
	if (year < 2009 || year > 2100) {
		return false;
	}
	if (month < 1 || month > 12) {
		return false;
	}

	int daysInMonth[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (day < 1 || day > daysInMonth[month - 1]) {
		return false;
	}

	return true;
}

bool  isValidValue(const std::string& value) {
    std::istringstream 	iss(value);
    double 				num;

    if (!(iss >> num) || !iss.eof()) {
        std::cout << "Error: Invalid value." << std::endl;
		return (false);
    }

    if (num < 0 || num > 2147483647) {
        if (num < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else
			std::cout << "Error: too large of a number." << std::endl;
		return (false);
    }
    return (true);
}

void BitcoinExchange::calculateBTC(std::string& date, std::string& value) {
	std::string closestDate;
	double closestValue = 0.0;

	for (std::map<std::string, double>::const_iterator it = dataBase.begin(); it != dataBase.end(); ++it) {
		const std::string& key = it->first;
		double value = it->second;

		if (key <= date) {
			if (key == date) {
				closestDate = key;
				closestValue = value;
				break;
			} else if (closestDate.empty() || key > closestDate) {
				closestDate = key;
				closestValue = value;
			}
		}
	}

	std::istringstream	iss(value);
	double				num;
	iss >> num;

	std::cout << date << "=> ";
	std::cout << num << " => ";
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
		if (!isValidDate(date)) {
			std::cout << "Error: bad input => " + date << std::endl;
			continue ;
		}
		if (!isValidValue(value)) {
			continue ;
		}
		calculateBTC(date, value);
	}
}
