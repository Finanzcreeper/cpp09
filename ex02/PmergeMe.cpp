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
}

PmergeMe::~PmergeMe() {
	delete[] pairs;
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
	return *this;
}
