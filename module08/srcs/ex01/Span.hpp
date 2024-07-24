#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <numeric>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>

// Of course, you will write your own tests and they will be way more thorough than the ones below.
// Test your Span at least with a minimum of 10,000 numbers. More would be even better.

// Develop a Span class that store a maximum of N integers.
class Span {
private:
	std::multiset<int> 	numbers;
	unsigned int			_N;
	Span();
public:
	~Span();
	Span(const Span& other);
	Span& operator=(const Span& other);

	// N is an unsigned int variable and will be the only parameter passed to the constructor.
	Span(unsigned int N);

	// This class will have a member function called addNumber() to add a single number to the Span.
	// It will be used in order to fill it.
	void addNumber(int n);

	// Next, implement two member functions: shortestSpan() and longestSpan()
	// They will respectively find out the shortest span or the longest span(or distance, if you prefer) between all the numbers stored, and return it.
	// If there are no numbers stored, or only one, no span can be found. Thus, throw an exception.
	size_t	shortestSpan();
	size_t	longestSpan();

	// Last but not least, it would be wonderful to fill your Span using a range of iterators.
	// Making thousands calls to addNumber() is so annoying. Implement a member function to add many numbers to your Span in one call.
	// template <typename Iterator>
	template<typename Iter>
	void addNumber(Iter begin, Iter end) {
		if (std::distance(begin, end) > static_cast<unsigned int>(_N - numbers.size())) {
			throw std::length_error("Adding range exceeds Span capacity.");
		}
		numbers.insert(begin, end);
	}

	static size_t	abs_difference(int a, int b);
};

#endif
