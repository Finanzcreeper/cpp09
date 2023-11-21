#include "PmergeMe.hpp"
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <utility>

PmergeMe::PmergeMe(int n, char **args) : size(n) {
	if (n % 2 == 1) {
		this->pairAmt = n/2+1;
		this->soloValue = true;
	}
	else {
		this->pairAmt = n/2;
		this->soloValue = false;
	}
	this->pairs = new std::pair<int,int>[this->pairAmt];
	this->sorted = new std::vector<int>;
	int c(0);
	for (int i = 0; i < this->pairAmt; ++i) {
		this->pairs[i].first = std::atoi(args[c++]);
		if (c < n)
			this->pairs[i].second = std::atoi(args[c++]);
	}
}

PmergeMe::PmergeMe(PmergeMe &src) : pairAmt(src.pairAmt), size(src.size), soloValue(src.soloValue){
	this->pairs = new std::pair<int,int>[src.pairAmt];
	for (int i = 0; i < src.pairAmt; ++i) {
		this->pairs[i].first = src.pairs[i].first;
		this->pairs[i].second = src.pairs[i].second;
	}
	this->sorted =  new std::vector<int>;
	std::vector<int>::iterator it = src.sorted->begin();
	while (it != src.sorted->end()) {
		this->sorted->insert(this->sorted->end(),*it++);
	}
}

PmergeMe::~PmergeMe() {
	delete[] pairs;
	delete sorted;
}

PmergeMe &PmergeMe::operator=(PmergeMe const& src) {
	if (src.size != this->size)
		this->size = src.size;
	if (src.pairAmt != this->pairAmt)
		this->pairAmt = src.pairAmt;
	if (src.soloValue != this->soloValue)
		this->soloValue = src.soloValue;
	if (src.pairs != this->pairs){
		delete[] this->pairs;
		this->pairs = new std::pair<int,int>[this->pairAmt];
		for (int i = 0; i < src.pairAmt; ++i) {
			this->pairs[i].first = src.pairs[i].first;
			this->pairs[i].second = src.pairs[i].second;
		}
	}
	if (this->sorted != src.sorted){
		delete this->sorted;
		this->sorted =  new std::vector<int>;
		std::vector<int>::iterator it = src.sorted->begin();
		while (it != src.sorted->end()) {
			this->sorted->insert(this->sorted->end(),*it++);
		}
	}
	return *this;
}

void PmergeMe::insertInSortedVec(int num) {
	std::vector<int>::iterator it = this->sorted->begin();
	while(it != this->sorted->end() && *it < num)
		++it;
	this->sorted->insert(it,num);
}

void PmergeMe::FillVecWithBiggestOutOfPairs() {
	int i(0);
	int a = this->pairAmt;
	if (soloValue == true)
		a -= 1;
	while (i < a) {
		if (this->pairs[i].first < this->pairs[i].second)
			insertInSortedVec(this->pairs[i].second);
		else
			insertInSortedVec(this->pairs[i].first);
		i++;
	}
}

void PmergeMe::printVec() {
	for (int i = 0; i < this->pairAmt; ++i) {
		std::cout << this->pairs[i].first << ", " << this->pairs[i].second << std::endl;
	}
	std::vector<int>::iterator it = this->sorted->begin();
	while (it != this->sorted->end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}
