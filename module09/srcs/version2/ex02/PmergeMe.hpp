#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <sstream>
#include <string>
#include <climits>

// CONTAINER
#include <vector>
#include <deque>

#include <ctime>
#include <iomanip>

#define DEQUEUE 4
#define VECTOR 22

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

using std::size_t;

class PmergeMe
{
private:
	size_t size;
	std::vector<int> original;
	std::vector<int> vector;
	std::deque<int> dequeue;
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);

public:
	PmergeMe();
	~PmergeMe();
	void insert(int ac, char *av[], int dataStructure);
	void setSize(int n);
	size_t getSize(void);
	std::vector<int>& getVector(void);
	std::deque<int>& getDequeue(void);
	
	void sort(int dataStructure);
	
	std::vector<int>::iterator vector_chunk_upper_bound(std::vector<int>& mainChain, size_t leftIdx, size_t rightIdx, int target, size_t chunk);
	std::deque<int>::iterator deque_chunk_upper_bound(std::deque<int>& mainChain, size_t leftIdx, size_t rightIdx, int target, size_t chunk);
	
	void fordJohnsonVec(int depth, std::vector<int>& vector);
	void fordJohnsonDeque(int depth, std::deque<int>& dequeue);
	
	void assembleDataRelationsVec(std::vector<int>& source, size_t chunk);
	void disassembleDataRelationsVec(std::vector<int>& source, size_t chunk);

	void assembleDataRelationsDeque(std::deque<int>& source, size_t chunk);
	void disassembleDataRelationsDeque(std::deque<int>& source, size_t chunk);

	int  power(int depth);
	void displayBefore(void);
	void displayAfter(int dataStructure);
	void displayTimeCost(clock_t start, clock_t end, int dataStructure);

public:
	class Error : public std::exception 
	{
	private:
		const char* _err_msg;
	public:
		Error(const char* _msg);
		const char *what() const throw();
	};
};

#endif
