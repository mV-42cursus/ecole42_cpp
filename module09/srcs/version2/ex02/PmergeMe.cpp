#include "PmergeMe.hpp"

PmergeMe::PmergeMe() :
	size(0),
	vector(size),
	dequeue(size) 
	{};

PmergeMe::~PmergeMe() {};

void PmergeMe::setSize(int n) { size = n; };
size_t PmergeMe::getSize(void) { return size; };
std::vector<int>& PmergeMe::getVector(void) { return vector; };
std::deque<int>& PmergeMe::getDequeue(void) { return dequeue; };

static bool containsNonDigitAlpha(const std::string& str) {
	for (size_t i=0; i < str.length(); i++) {
		if (std::isalpha(str[i]) && !std::isdigit(str[i])) {
			return true;
		}
	}
	return false;
}

static bool stringToInt(const std::string& str) {
	std::istringstream iss(str);
	long temp;
		
	if (!(iss >> temp)) {
		return false;
	}

	if (temp < INT_MIN || temp > INT_MAX) {
		return false;
	}

	return true;
}

void PmergeMe::insert(int ac, char *av[], int dataStructure) {
	// ./PMergeMe 의 형태 예외처리
	if (ac == 1) {
		throw (PmergeMe::Error ("./PMergeMe <integers...>"));
	}
	
	// ./PMergeMe 12 3 5a 이런 이상한 형태는 아예 안받음
	for (int i = 1; i < ac; i++) {
		if (containsNonDigitAlpha(av[i])) {
			throw (PmergeMe::Error ("Only digits allowed.\nDO NOT contain alphbets."));
		}
	}

	// INT CONVERSION 체크
	for (int i = 1; i < ac; i++) {
		if (!stringToInt(av[i])) {
			throw (PmergeMe::Error ("Must be within integer value range."));
		}
	}

	// 원소의 갯수 기록해주기
	setSize(ac - 1);

	// 원본 배열 기록해주기
	if (original.size() == 0) {
		for (int i = 1; i < ac; i++) {
			original.push_back(atoi(av[i]));
		}
	}

	if (dataStructure == VECTOR) {
		vector = std::vector<int>(original.begin(), original.end());
	} else {
		dequeue = std::deque<int>(original.begin(), original.end());
	}
}

void PmergeMe::sort(int dataStructure) {
	if (dataStructure == VECTOR) {
		fordJohnsonVec(0, vector);
	} else {
		fordJohnsonDeque(0, dequeue);
	}
}

int PmergeMe::power(int depth) {
	if (depth == 0 || depth < 0)
		return (1);
	return (1 << depth);
}

void PmergeMe::disassembleDataRelationsVec(std::vector<int>& source, size_t chunk) {
	// [STEP 3] :: data Sort
	std::vector<int> mainChain;
	std::vector<int> subChain;

	// mainChain과 subChain 구성
	size_t fullChunks = source.size() / chunk;

	for (size_t i = 0; i < fullChunks; i += 2) {
		if (fullChunks == 1)
			return ;
		if (i + 1 < fullChunks) {
			mainChain.insert(mainChain.end(), source.begin() + i * chunk, source.begin() + (i + 1) * chunk);
			subChain.insert(subChain.end(), source.begin() + (i + 1) * chunk, source.begin() + (i + 2) * chunk);
		} else {
			// 홀수 개의 chunk일 경우 마지막 chunk
			subChain.insert(subChain.end(), source.begin() + i * chunk, source.begin() + (i + 1) * chunk);
		}
	}

	// subChain에 있는 chunk들을 jacobstal's number에 따라 mainChain에 기입 정렬해주기
	size_t subChainChunks = subChain.size() / chunk;
	size_t insertedChunks = 0;
	int jacobsthalPrev = 1;
	int jacobsthalCurr = 1;

	while (insertedChunks < subChainChunks) {
		// jacobstal's number에 해당하는 index찾은 후,
		// chunk만큼 mainChain에 삽입 해주기
		size_t jacobsthalIndex = jacobsthalCurr - 1; // 0-based index로 변환
		if (jacobsthalIndex < subChainChunks) {
			// 이진탐색으로 삽입 위치 찾기
			std::vector<int>::iterator insertPos = vector_chunk_upper_bound(
				mainChain, 0, jacobsthalIndex * chunk,
				subChain[jacobsthalIndex * chunk],
				chunk
			);

			mainChain.insert(insertPos, 
							subChain.begin() + jacobsthalIndex * chunk, 
							subChain.begin() + (jacobsthalIndex + 1) * chunk);
			++insertedChunks;

			// jacobstal's number에 해당하는 index chunk삽입 후 그 전의 index에 해당하는 chunk들을 역순으로 mainChain에 삽입해 주기
			// 예를들어 jacobstal수가 11이었다면, 10 9 8 7 6 순으로 삽입
			for (int i = jacobsthalIndex - 1; i >= jacobsthalPrev && insertedChunks < subChainChunks; --i) {
				// 이진탐색으로 삽입 위치 찾기
				insertPos = vector_chunk_upper_bound(mainChain, 0, i * chunk, subChain[i * chunk], chunk);
				mainChain.insert(insertPos, subChain.begin() + i * chunk, 
								subChain.begin() + (i + 1) * chunk);
				++insertedChunks;
			}
		} else {
			// 다음 jacobstal 수가 없을 경우, 남은 chunk들은 역순으로 삽입
			for (size_t i = subChainChunks; i-- > insertedChunks; ) {
				// 이진탐색으로 삽입 위치 찾기
				std::vector<int>::iterator insertPos = vector_chunk_upper_bound(mainChain, 0, i * chunk, subChain[i * chunk], chunk);
				mainChain.insert(insertPos, subChain.begin() + i * chunk, 
								subChain.begin() + (i + 1) * chunk);
			}
			break;
		}

		// 다음 Jacobsthal 수 계산
		int temp = jacobsthalCurr;
		jacobsthalCurr = jacobsthalCurr + 2 * jacobsthalPrev;
		jacobsthalPrev = temp;
	}
	std::copy(mainChain.begin(), mainChain.end(), source.begin());
}

void PmergeMe::assembleDataRelationsVec(std::vector<int>& source, size_t chunk) {
	int tournamentCnt = source.size() / (2 * chunk);
	int validElementCnt = tournamentCnt * 2 * chunk;

	// 두 개의 페어 비교 후 승자 위치를 각각 승자 패자 벡터에 기록해주기
	std::vector<int> winners;
	std::vector<int> losers;

	// 토너먼트 수행
	for (int i = 0; i < tournamentCnt; i++) {
		int playerIdx1 = 2 * i * chunk;
		int playerIdx2 = (2 * i + 1) * chunk;
		if (source[playerIdx1] >= source[playerIdx2]) {
			winners.push_back(playerIdx1);
			losers.push_back(playerIdx2);
		} else {
			winners.push_back(playerIdx2);
			losers.push_back(playerIdx1);
		}
	}

	// 수행결과 destination에 반영
	std::vector<int> destination(validElementCnt);
	for (int i = 0; i < tournamentCnt; i++) {
		// 승자를 짝수 인덱스에 배치
		std::copy(source.begin() + winners[i], 
				source.begin() + winners[i] + chunk, 
				destination.begin() + 2 * i * chunk);

		// 패자를 홀수 인덱스에 배치
		std::copy(source.begin() + losers[i], 
				source.begin() + losers[i] + chunk, 
				destination.begin() + (2 * i + 1) * chunk);
	}

	std::copy(destination.begin(), destination.end(), source.begin());
}

void PmergeMe::fordJohnsonVec(int depth, std::vector<int>& source) {
	size_t chunk = power(depth);
	if (source.size() < 2 * chunk) {
		disassembleDataRelationsVec(source, chunk);
		return ;
	}

	// [STEP 1] :: assembleDataRelations
	assembleDataRelationsVec(source, chunk);

	// [STEP 2] 재귀 호출
	fordJohnsonVec(depth + 1, source);

	// [STEP 3] 데이터 스택 해제 (정렬)
	disassembleDataRelationsVec(source, chunk);
}

std::vector<int>::iterator PmergeMe::vector_chunk_upper_bound(
									std::vector<int>& mainChain, size_t leftIdx, size_t rightIdx, 
									int target, size_t chunk)
{
	/*
		Binary search 구현
		역할 :: 주어진 값 (target) 보다 큰 첫번째 원소의 위치를 찾고
		해당 이터레이터 위치를 반환 
	*/
	while (leftIdx < rightIdx) {
		size_t midIdx = leftIdx + ((rightIdx - leftIdx) / chunk / 2) * chunk;
		if (midIdx >= mainChain.size()) {
			rightIdx = midIdx;
		}

		int midValue = mainChain[midIdx];

		if (midValue <= target) {
			leftIdx = midIdx + chunk;
		} else {
			rightIdx = midIdx;
		}
	}

	// 중복값 처리 target과 같은 값을 가진 마지막 원소의 다음 위치 찾기
	while (leftIdx < mainChain.size() && mainChain[leftIdx] <= target) {
		leftIdx += chunk;
	}

	return mainChain.begin() + leftIdx;
}

std::deque<int>::iterator PmergeMe::deque_chunk_upper_bound(
									std::deque<int>& mainChain, size_t leftIdx, size_t rightIdx, 
									int target, size_t chunk) {
	/*
		이진탐색 (Binary search) 구현
		역할 :: 주어진 값 (target) 보다 큰 첫번째 원소의 위치를 찾고
		해당 이터레이터 위치를 반환 
	*/

	while (leftIdx < rightIdx) {
		size_t midIdx = leftIdx + ((rightIdx - leftIdx) / chunk / 2) * chunk;
		if (midIdx >= mainChain.size()) {
			rightIdx = midIdx;
		}

		int midValue = mainChain[midIdx];

		if (midValue <= target) {
			leftIdx = midIdx + chunk;
		} else {
			rightIdx = midIdx;
		}
	}

	// 중복값 처리 즉, target과 같은 값을 가진 마지막 원소의 마지막 위치 찾기
	while (leftIdx < mainChain.size() && mainChain[leftIdx] <= target) {
		leftIdx += chunk;
	}

	return mainChain.begin() + leftIdx;
}

PmergeMe::Error::Error(const char* _msg) : _err_msg(_msg) {}

const char* PmergeMe::Error::what() const throw() {
	return _err_msg;
}

void PmergeMe::displayBefore(void) {
	std::vector<int>::const_iterator cit;
	std::cout << "Before: ";
	for (cit = original.begin(); cit != original.end(); ++cit) {
		std::cout << *cit << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::displayAfter(int dataStructure) {
	std::cout << GREEN << "After: ";
	if (dataStructure == VECTOR) {
		std::vector<int>::const_iterator cit;
		for (cit = vector.begin(); cit != vector.end(); ++cit) {
			std::cout << *cit << " ";
		}
		std::cout << std::endl;
	} else if (dataStructure == DEQUEUE) {
		std::deque<int>::const_iterator cit;
		for (cit = dequeue.begin(); cit != dequeue.end(); ++cit) {
			std::cout << *cit << " ";
		}
		std::cout << std::endl;
	}
	std::cout << WHITE;
}

void PmergeMe::displayTimeCost(clock_t start, clock_t end, int dataStructure) {
	double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // 마이크로초로 변환
	std::string dataStructureName = (dataStructure == VECTOR) ? "vector" : "deque";

	std::cout << "Time to process a range of " 
			  << getSize() 
			  << " elements with std::[" << dataStructureName << "] : "
			  << std::fixed << std::setprecision(5) << time
			  << " us"
			  << std::endl;
}

void PmergeMe::disassembleDataRelationsDeque(std::deque<int>& source, size_t chunk) {
	// [STEP 3] :: data Sort
	std::deque<int> mainChain;
	std::deque<int> subChain;

	// mainChain과 subChain 구성
	size_t fullChunks = source.size() / chunk;

	for (size_t i = 0; i < fullChunks; i += 2) {
		if (fullChunks == 1)
			return ;
		if (i + 1 < fullChunks) {
			mainChain.insert(mainChain.end(), source.begin() + i * chunk, source.begin() + (i + 1) * chunk);
			subChain.insert(subChain.end(), source.begin() + (i + 1) * chunk, source.begin() + (i + 2) * chunk);
		} else {
			// 홀수 개의 chunk일 경우 마지막 chunk
			subChain.insert(subChain.end(), source.begin() + i * chunk, source.begin() + (i + 1) * chunk);
		}
	}

	// subChain에 있는 chunk들을 jacobstal's number에 따라 mainChain에 기입 정렬해주기
	size_t subChainChunks = subChain.size() / chunk;
	size_t insertedChunks = 0;
	int jacobsthalPrev = 1;
	int jacobsthalCurr = 1;

	while (insertedChunks < subChainChunks) {
		// jacobstal's number에 해당하는 index찾은 후,
		// chunk만큼 mainChain에 삽입 해주기
		size_t jacobsthalIndex = jacobsthalCurr - 1; // 0-based index로 변환
		if (jacobsthalIndex < subChainChunks) {
			// 이진탐색으로 삽입 위치 찾기
			std::deque<int>::iterator insertPos = deque_chunk_upper_bound(
				mainChain, 0, jacobsthalIndex * chunk,
				subChain[jacobsthalIndex * chunk],
				chunk
			);

			mainChain.insert(insertPos, 
							subChain.begin() + jacobsthalIndex * chunk, 
							subChain.begin() + (jacobsthalIndex + 1) * chunk);
			++insertedChunks;

			// jacobstal's number에 해당하는 index chunk삽입 후 그 전의 index에 해당하는 chunk들을 역순으로 mainChain에 삽입해 주기
			// 예를들어 jacobstal수가 11이었다면, 10 9 8 7 6 순으로 삽입
			for (int i = jacobsthalIndex - 1; i >= jacobsthalPrev && insertedChunks < subChainChunks; --i) {
				// 이진탐색으로 삽입 위치 찾기
				insertPos = deque_chunk_upper_bound(mainChain, 0, i * chunk, subChain[i * chunk], chunk);
				mainChain.insert(insertPos, subChain.begin() + i * chunk, 
								subChain.begin() + (i + 1) * chunk);
				++insertedChunks;
			}
		} else {
			// 다음 jacobstal 수가 없을 경우, 남은 chunk들은 역순으로 삽입
			for (size_t i = subChainChunks; i-- > insertedChunks; ) {
				// 이진탐색으로 삽입 위치 찾기
				std::deque<int>::iterator insertPos = deque_chunk_upper_bound(mainChain, 0, i * chunk, subChain[i * chunk], chunk);
				mainChain.insert(insertPos, subChain.begin() + i * chunk, 
								subChain.begin() + (i + 1) * chunk);
			}
			break;
		}

		// 다음 Jacobsthal 수 계산
		int temp = jacobsthalCurr;
		jacobsthalCurr = jacobsthalCurr + 2 * jacobsthalPrev;
		jacobsthalPrev = temp;
	}
	std::copy(mainChain.begin(), mainChain.end(), source.begin());
}

void PmergeMe::assembleDataRelationsDeque(std::deque<int>& source, size_t chunk) {
	int tournamentCnt = source.size() / (2 * chunk);
	int validElementCnt = tournamentCnt * 2 * chunk;

	// 두 개의 페어 비교 후 승자 위치를 각각 승자 패자 벡터에 기록해주기
	std::deque<int> winners;
	std::deque<int> losers;

	// 토너먼트 수행
	for (int i = 0; i < tournamentCnt; i++) {
		int playerIdx1 = 2 * i * chunk;
		int playerIdx2 = (2 * i + 1) * chunk;
		if (source[playerIdx1] >= source[playerIdx2]) {
			winners.push_back(playerIdx1);
			losers.push_back(playerIdx2);
		} else {
			winners.push_back(playerIdx2);
			losers.push_back(playerIdx1);
		}
	}

	// 수행결과 destination에 반영
	std::deque<int> destination(validElementCnt);
	for (int i = 0; i < tournamentCnt; i++) {
		// 승자를 짝수 인덱스에 배치
		std::copy(source.begin() + winners[i], 
				source.begin() + winners[i] + chunk, 
				destination.begin() + 2 * i * chunk);

		// 패자를 홀수 인덱스에 배치
		std::copy(source.begin() + losers[i], 
				source.begin() + losers[i] + chunk, 
				destination.begin() + (2 * i + 1) * chunk);
	}

	std::copy(destination.begin(), destination.end(), source.begin());
}

void PmergeMe::fordJohnsonDeque(int depth, std::deque<int>& source) {
	size_t chunk = power(depth);

	if (source.size() / chunk <= 2) {
		disassembleDataRelationsDeque(source, chunk);
		return ;
	}

	// [STEP 1] :: assembleDataRelations
	assembleDataRelationsDeque(source, chunk);

	// [STEP 2] 재귀 호출
	fordJohnsonDeque(depth + 1, source);

	// [STEP 3] 데이터 스택 해제 (정렬)
	disassembleDataRelationsDeque(source, chunk);
}
