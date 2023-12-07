
#ifndef CPP09_PMERGEME_HPP
#define CPP09_PMERGEME_HPP

#include <vector>
#include <utility>
#include <list>
#include <iostream>

class PmergeMe {
private:
	int pairAmt;
	int size;
	bool soloValue;
	std::pair<int,int> *pairs;
public:
	PmergeMe(int n, char* args[]);
	PmergeMe(PmergeMe& src);

	~PmergeMe();

	PmergeMe& operator=(PmergeMe const& src);

	template<typename O> void SortJohnson(O &container) {
		int i(0);
		int a = this->pairAmt;
		if (soloValue == true)
			a -= 1;
		while (i < a) {
			if (this->pairs[i].first < this->pairs[i].second) {
				std::swap(this->pairs[i].first, this->pairs[i].second);
			}
			insertInSortedO(container, this->pairs[i].first);
			++i;
		}
		i = 0;
		while (i < this->pairAmt) {
			if (this->soloValue == true && i == this->pairAmt - 1) {
				insertInSortedO(container, this->pairs[i].first);
				break;
			}
			insertInSortedO(container, this->pairs[i].second);
			i++;
		}
	}

	template<typename O> void insertInSortedO(O &container, int num) {
		typename O::iterator it = container.begin();
		if (it != container.end()) {
			while (it != container.end() && *it < num)
				++it;
		}
		container.insert(it, num);
	}

	template<typename O> void printO(O &container) {
		std::cout << "Output:	" ;
		typename O::iterator it = container.begin();
		while (it != container.end()) {
			std::cout << *it << " ";
			it++;
		}
		std::cout << std::endl;
	}
};

#endif //CPP09_PMERGEME_HPP
