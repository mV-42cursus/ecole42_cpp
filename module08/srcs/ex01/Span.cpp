#include "Span.hpp"

// OCCF
Span::Span() {}
Span::~Span() {}
Span::Span(const Span& other) : _N(other._N) {
	this->numbers = other.numbers;
}

Span& Span::operator=(const Span& other)
{
	if (this == &other)
		return (*this);
	this->_N = other._N;
	this->numbers = other.numbers;
	return (*this);
}

Span::Span(unsigned int N) : _N(N) {}

void Span::addNumber(int n) {
	if (numbers.size() >= _N)
		throw std::length_error("Span is already full.");
	numbers.insert(n);
}

size_t Span::abs_difference(int a, int b) {
	return (static_cast<size_t>(std::abs(a-b)));
}

size_t Span::shortestSpan() {
	if (numbers.size() < 2) {
		throw std::logic_error("Not enough numbers to compute span.");
	}
	std::vector<size_t> differences(numbers.size());
	std::adjacent_difference(numbers.begin(), numbers.end(), differences.begin(), Span::abs_difference);
	// std::cout << "[";
	// for(std::vector<size_t>::iterator it = differences.begin(); it != differences.end(); ++it) {
	// 	int n =  *it;
	// 	std::cout << n << " ";
	// }
	// std::cout << "]" << std::endl;
	std::vector<size_t>::iterator minIt = std::min_element(differences.begin() + 1, differences.end());
	return (*minIt);
}

size_t Span::longestSpan() {
	if (numbers.size() < 2) {
		throw std::logic_error("Not enough numbers to compute span.");
	}
	return (static_cast<size_t>(*(numbers.rbegin())) - static_cast<size_t>(*(numbers.begin())));
}
