
#ifndef CPP09_PMERGEME_HPP
#define CPP09_PMERGEME_HPP

#include <vector>
#include <utility>
#include <list>

class PmergeMe {
private:
	int pairAmt;
	int size;
	bool soloValue;
	std::pair<int,int> *pairs;
	std::vector<int> *sortedVec;
	std::list<int> *sortedList;
public:
	PmergeMe(int n, char* args[]);
	PmergeMe(PmergeMe& src);

	~PmergeMe();

	PmergeMe& operator=(PmergeMe const& src);

	void printVec();
	void printList();

	void SortBiggiesVec();
	void SortSmalliesVec();
	void insertInSortedVec(int num);
	void SortWithVector();
	void SortBiggiesList();
	void SortSmalliesList();
	void insertInSortedList(int num);
	void SortWithList();
};


#endif //CPP09_PMERGEME_HPP
