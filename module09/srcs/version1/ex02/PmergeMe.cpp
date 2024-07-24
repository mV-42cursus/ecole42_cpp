#include "PmergeMe.hpp"

fordJohnson::fordJohnson() :
	size(0),
	vector(size),
	dequeue(size) 
	{};

fordJohnson::~fordJohnson() {};

void fordJohnson::setSize(int n) { size = n; };
size_t fordJohnson::getSize(void) { return size; };
std::vector<int>& fordJohnson::getVector(void) { return vector; };
std::deque<int>& fordJohnson::getDequeue(void) { return dequeue; };

bool containsNonDigitAlpha(const std::string& str) {
	for (size_t i=0; i < str.length(); i++) {
		if (std::isalpha(str[i]) && !std::isdigit(str[i])) {
			return true;
		}
	}
	return false;
}

bool stringToInt(const std::string& str) {
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

void fordJohnson::insert(int ac, char *av[], int dataStructure) {
	// ./PMergeMe 의 형태 예외처리
	if (ac == 1) {
		throw (fordJohnson::Error ("./PMergeMe <integers...>"));
	}
	// ./PMergeMe 12 3 5a 이런 이상한 형태는 아예 안받음
	for (int i = 1; i < ac; i++) {
		if (containsNonDigitAlpha(av[i])) {
			throw (fordJohnson::Error ("Only digits allowed.\nDO NOT contain alphbets."));
		}
	}

	// INT RANGE 체크
	for (int i = 1; i < ac; i++) {
		if (!stringToInt(av[i])) {
			throw (fordJohnson::Error ("Must be within integer value range."));
		}
	}

	// 원소의 갯수 기록해주기
	(*this).setSize(ac - 1);

	// 원본 배열 기록해주기
	if ((*this).original.size() == 0) {
		for (int i = 1; i < ac; i++) {
			(*this).original.push_back(atoi(av[i]));
		}
	}

	if (dataStructure == VECTOR) {
		for (int i=1; i < ac; i++) {
			vector.push_back(atoi(av[i]));
		}
	} else {
		for (int i=1; i < ac; i++) {
			dequeue.push_back(atoi(av[i]));
		}
	}
}

void fordJohnson::sort(int dataStructure) {

	if (dataStructure == VECTOR) {
		dfsVec(0, vector);
	}   else {
		dfsDeque(0, dequeue);
	}
}

int fordJohnson::power(int depth) {
	int res = 1;
	if (depth == 0 || depth < 0)
		return (1);
	while (depth-- > 0)
		res *= 2;
	return (res);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
void fordJohnson::disassembleDataRelationsVec(std::vector<int>& source, size_t chunk) {
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
			std::vector<int>::iterator insertPos = mainChain.begin();
			while (insertPos != mainChain.end() && *insertPos < subChain[jacobsthalIndex * chunk]) {
				insertPos += chunk;
			}

			mainChain.insert(insertPos, subChain.begin() + jacobsthalIndex * chunk, subChain.begin() + (jacobsthalIndex + 1) * chunk);
				++insertedChunks;

			// jacobstal's number에 해당하는 index chunk삽입 후 그 전의 index에 해당하는 chunk들을 역순으로 mainChain에 삽입해 주기
			// 예를들어 jacobstal수가 11이었다면, 10 9 8 7 6 순으로 삽입
			for (int i = jacobsthalIndex - 1; i >= jacobsthalPrev && insertedChunks < subChainChunks; --i) {
				insertPos = mainChain.begin();
				while (insertPos != mainChain.end() && *insertPos < subChain[i * chunk]) {
					++insertPos;
				}
				mainChain.insert(insertPos, subChain.begin() + i * chunk, 
								subChain.begin() + (i + 1) * chunk);
				++insertedChunks;
			}
		} else {
			// 다음 jacobstal 수가 없을 경우, 남은 chunk들은 역순으로 삽입
			for (size_t i = subChainChunks; i-- > insertedChunks; ) {
				std::vector<int>::iterator insertPos = mainChain.begin();
				while (insertPos != mainChain.end() && *insertPos < subChain[i * chunk]) {
					++insertPos;
				}
				mainChain.insert(insertPos, subChain.begin() + i * chunk, 
								subChain.begin() + (i + 1) * chunk);
			}
			break;  // 모든 chunk를 삽입했으므로 루프 종료
		}

		// 다음 Jacobsthal 수 계산
		int temp = jacobsthalCurr;
		jacobsthalCurr = jacobsthalCurr + 2 * jacobsthalPrev;
		jacobsthalPrev = temp;
	}
	std::copy(mainChain.begin(), mainChain.end(), source.begin());
}

void fordJohnson::assembleDataRelationsVec(std::vector<int>& source, size_t chunk) {
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

void fordJohnson::dfsVec(int depth, std::vector<int>& source) {
	size_t chunk = power(depth);
	if (source.size() / chunk <= 2) {
		disassembleDataRelationsVec(source, chunk);
		return ;
	}

	// [STEP 1] :: assembleDataRelationsx
	assembleDataRelationsVec(source, chunk);

	// [STEP 2] dfs 재귀 호출
	dfsVec(depth + 1, source);

	// [STEP 3] 데이터 해제 (정렬)
	disassembleDataRelationsVec(source, chunk);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
void fordJohnson::disassembleDataRelationsDeque(std::deque<int>& source, size_t chunk) {
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
			std::deque<int>::iterator insertPos = mainChain.begin();
			while (insertPos != mainChain.end() && *insertPos < subChain[jacobsthalIndex * chunk]) {
				insertPos += chunk;
			}

			mainChain.insert(insertPos, subChain.begin() + jacobsthalIndex * chunk, subChain.begin() + (jacobsthalIndex + 1) * chunk);
				++insertedChunks;

			// jacobstal's number에 해당하는 index chunk삽입 후 그 전의 index에 해당하는 chunk들을 역순으로 mainChain에 삽입해 주기
			// 예를들어 jacobstal수가 11이었다면, 10 9 8 7 6 순으로 삽입
			for (int i = jacobsthalIndex - 1; i >= jacobsthalPrev && insertedChunks < subChainChunks; --i) {
				insertPos = mainChain.begin();
				while (insertPos != mainChain.end() && *insertPos < subChain[i * chunk]) {
					++insertPos;
				}
				mainChain.insert(insertPos, subChain.begin() + i * chunk, 
								subChain.begin() + (i + 1) * chunk);
				++insertedChunks;
			}
		} else {
			// 다음 jacobstal 수가 없을 경우, 남은 chunk들은 역순으로 삽입
			for (size_t i = subChainChunks; i-- > insertedChunks; ) {
				std::deque<int>::iterator insertPos = mainChain.begin();
				while (insertPos != mainChain.end() && *insertPos < subChain[i * chunk]) {
					++insertPos;
				}
				mainChain.insert(insertPos, subChain.begin() + i * chunk, 
								subChain.begin() + (i + 1) * chunk);
			}
			break;  // 모든 chunk를 삽입했으므로 루프 종료
		}

		// 다음 Jacobsthal 수 계산
		int temp = jacobsthalCurr;
		jacobsthalCurr = jacobsthalCurr + 2 * jacobsthalPrev;
		jacobsthalPrev = temp;
	}
	std::copy(mainChain.begin(), mainChain.end(), source.begin());
}

void fordJohnson::assembleDataRelationsDeque(std::deque<int>& source, size_t chunk) {
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

void fordJohnson::dfsDeque(int depth, std::deque<int>& source) {
	size_t chunk = power(depth);
	if (source.size() / chunk <= 2) {
		disassembleDataRelationsDeque(source, chunk);
		return ;
	}

	// [STEP 1] :: assembleDataRelationsx
	assembleDataRelationsDeque(source, chunk);

	// [STEP 2] dfs 재귀 호출
	dfsDeque(depth + 1, source);

	// [STEP 3] 데이터 해제 (정렬)
	disassembleDataRelationsDeque(source, chunk);
}

fordJohnson::Error::Error(const char* _msg) {
	int i;

	for(i = 0 ; _msg[i] != '\0' && i < 1023; ++i) {
		err_msg[i] = _msg[i];
	}
	err_msg[i] = '\0';
}

const char* fordJohnson::Error::what() const throw() {
	return err_msg;
}

void fordJohnson::displayBefore(void) {
	std::vector<int>::const_iterator cit;
	std::cout << "Before: ";
	for (cit = original.begin(); cit != original.end(); ++cit) {
		std::cout << *cit << " ";
	}
	std::cout << std::endl;
}

void fordJohnson::displayAfter(int dataStructure) {
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

void fordJohnson::displayTimeCost(clock_t start, clock_t end, int dataStructure) {
    double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // 마이크로초로 변환
    std::string dataStructureName = (dataStructure == VECTOR) ? "vector" : "deque";

    std::cout << "Time to process a range of " 
              << getSize() 
              << " elements with std::[" << dataStructureName << "] : "
              << std::fixed << std::setprecision(5) << time
              << " us"
              << std::endl;
}
