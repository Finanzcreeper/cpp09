
#ifndef CPP09_PMERGEME_HPP
#define CPP09_PMERGEME_HPP

#include <vector>
#include <utility>
#include <list>
#include <iostream>
#include <cmath>

class PmergeMe {
private:
	int pairAmt;
	int size;
	bool soloValue;
	int solo;
	std::pair<int,int> *pairs;
public:
	PmergeMe(int n, char* args[]);
	PmergeMe(PmergeMe& src);

	~PmergeMe();

	PmergeMe& operator=(PmergeMe const& src);

	template<typename O>
	void SortJohnson(O &container) {
		std::vector<std::pair<int,int> > test;
		int i(0);
		if (this->pairAmt == 0) {
				insertInSortedO(container,this->solo);
				return;
		}
		while (i < this->pairAmt) {
			if (this->pairs[i].first < this->pairs[i].second) {
				std::swap(this->pairs[i].first, this->pairs[i].second);
			}
			insertInSortedtest(test, this->pairs[i]);
			++i;
		}
		makeS(test,container);
		std::vector<std::pair<int,int> >::iterator it = test.begin();
		insertTest(test, container, it, 2, 0, 2, 2, false);
		if (this->soloValue == true)
			insertInSortedO(container, this->solo);
	}

	template<typename O>
	void insertTest(std::vector<std::pair<int,int> > &test, O &container,std::vector<std::pair<int,int> >::iterator it, int b, int floor, int pot, int e, bool exit) {
		while (floor < b ) {
			if ((e - floor) >= this->pairAmt) {
				floor = (e - this->pairAmt)+1;
				exit = true;
			}
			if (e-floor != 0)
				insertInSortedO(container, (it + (e - floor))->second);
			++floor;
		}
		b = std::pow(2,pot++) - b;
		e += b;
		if (exit == false)
			insertTest(test,container,it,b,0,pot,e, exit);
	}

	template<typename O>
	void insertInSortedO(O &container, int num) {
		typename O::iterator it = container.begin();
		if (it != container.end()) {
			while (it != container.end() && *it < num)
				++it;
		}
		container.insert(it, num);
	}

	template<typename O>
	void makeS(std::vector<std::pair<int,int> > &test, O &container) {
		std::vector<std::pair<int,int> >::iterator lit = test.begin();
		container.insert(container.begin(), lit++->first);
		while (lit != test.end()) {
			container.insert(container.end(), lit++->first);
		}
		container.insert(container.begin(),test.begin()->second);
	}

	template<typename O>
	void printO(O &container) {
		std::cout << "Output:	" ;
		typename O::iterator it = container.begin();
		while (it != container.end()) {
			std::cout << *it << " ";
			it++;
		}
		std::cout << std::endl;
	}
	void insertInSortedtest(std::vector<std::pair<int,int> > &test, std::pair<int,int> num);
};

#endif //CPP09_PMERGEME_HPP
