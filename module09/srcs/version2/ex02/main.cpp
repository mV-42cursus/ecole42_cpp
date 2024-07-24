#include "PmergeMe.hpp"

#ifdef DEBUG
	#include <algorithm>
#endif

int main(int ac, char *av[])
{
	PmergeMe algorithm;
	try {
		// VECTOR 시간 측정 후 결과 표시
		clock_t vecStart = clock();
		algorithm.insert(ac, av, VECTOR);
		algorithm.sort(VECTOR);
		clock_t vecEnd = clock();
		
		// DEQUE 시간 측정 후 결과 표시
		clock_t dequeStart = clock();
		algorithm.insert(ac, av, DEQUEUE);
		algorithm.sort(DEQUEUE);
		clock_t dequeEnd = clock();

		// // DISPLAY RESULT
		algorithm.displayBefore();
		algorithm.displayAfter(VECTOR);

#ifdef DEBUG
		algorithm.displayAfter(DEQUEUE);
#endif

		// DISPLAY TIME CONSUMPTION
		algorithm.displayTimeCost(vecStart, vecEnd, VECTOR);
		algorithm.displayTimeCost(dequeStart, dequeEnd, DEQUEUE);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
		return (1);
	}
#ifdef DEBUG
	if (std::is_sorted(algorithm.getVector().begin(), algorithm.getVector().end()))
		std::cout << GREEN << "\nPmergeMe [std::vector] SUCCESSFUL" << WHITE;
	else
		std::cout << RED << "\nPmergeMe [std::vector] FAIL" << WHITE;
	if (std::is_sorted(algorithm.getDequeue().begin(), algorithm.getDequeue().end()))
		std::cout << GREEN << "\nPmergeMe [std::deque ] SUCCESSFUL" << std::endl << WHITE;
	else
		std::cout << RED << "\nPmergeMe [std::deque]  FAIL" << std::endl << WHITE;
#endif
	return (0);
}
