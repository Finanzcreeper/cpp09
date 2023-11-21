
#ifndef CPP09_PMERGEME_HPP
#define CPP09_PMERGEME_HPP

#include <vector>
#include <utility>

class PmergeMe {
private:
	int pairAmt;
	int size;
	bool soloValue;
	std::pair<int,int> *pairs;
	std::vector<int> *sorted;
public:
	PmergeMe(int n, char* args[]);
	PmergeMe(PmergeMe& src);

	~PmergeMe();

	void printVec();

	PmergeMe& operator=(PmergeMe const& src);
	void FillVecWithBiggestOutOfPairs();
	void insertInSortedVec(int num);
};


#endif //CPP09_PMERGEME_HPP
