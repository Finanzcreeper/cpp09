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
	this->sortedVec = new std::vector<int>;
	this->sortedList = new std::list<int>;
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
	this->sortedList = new std::list<int>;
	std::list<int>::iterator lt = src.sortedList->begin();
	while (lt != src.sortedList->end()) {
		this->sortedList->insert(this->sortedList->end(),*lt++);
	}
	this->sortedVec =  new std::vector<int>;
	std::vector<int>::iterator it = src.sortedVec->begin();
	while (it != src.sortedVec->end()) {
		this->sortedVec->insert(this->sortedVec->end(), *it++);
	}
}

PmergeMe::~PmergeMe() {
	delete[] pairs;
	delete sortedVec;
	delete sortedList;
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
	if (this->sortedVec != src.sortedVec){
		delete this->sortedVec;
		this->sortedVec =  new std::vector<int>;
		std::vector<int>::iterator it = src.sortedVec->begin();
		while (it != src.sortedVec->end()) {
			this->sortedVec->insert(this->sortedVec->end(), *it++);
		}
	}
	if (this->sortedList != src.sortedList) {
		delete this->sortedList;
		this->sortedList = new std::list<int>;
		std::list<int>::iterator lt = src.sortedList->begin();
		while (lt != src.sortedList->end()) {
			this->sortedList->insert(this->sortedList->end(),*lt++);
		}
	}
	return *this;
}

void PmergeMe::insertInSortedVec(int num) {
	std::vector<int>::iterator it = this->sortedVec->begin();
	while(it != this->sortedVec->end() && *it < num)
		++it;
	this->sortedVec->insert(it, num);
}

void PmergeMe::insertInSortedList(int num) {
	std::list<int>::iterator it = this->sortedList->begin();
	while (it != this->sortedList->end() && *it < num)
		++it;
	this->sortedList->insert(it, num);
}

void PmergeMe::SortBiggiesVec() {
	int i(0);
	int a = this->pairAmt;
	if (soloValue == true)
		a -= 1;
	while (i < a) {
		if (this->pairs[i].first < this->pairs[i].second){
			insertInSortedVec(this->pairs[i].second);
		}
		else
			insertInSortedVec(this->pairs[i].first);
		i++;
	}
}

void PmergeMe::SortSmalliesVec() {
	int i(0);
	while (i < this->pairAmt) {
		if (this->soloValue == true && i == this->pairAmt - 1) {
			insertInSortedVec(this->pairs[i].first);
			break;
		}
		if (this->pairs[i].first < this->pairs[i].second){
			insertInSortedVec(this->pairs[i].first);
		}
		else {
			insertInSortedVec(this->pairs[i].second);
		}
		i++;
	}
}

void PmergeMe::SortBiggiesList() {
	int i(0);
	int a = this->pairAmt;
	if (soloValue == true)
		a -= 1;
	while (i < a) {
		if (this->pairs[i].first < this->pairs[i].second){
			insertInSortedList(this->pairs[i].second);
		}
		else
			insertInSortedList(this->pairs[i].first);
		i++;
	}
}

void PmergeMe::SortSmalliesList() {
	int i(0);
	while (i < this->pairAmt) {
		if (this->soloValue == true && i == this->pairAmt - 1) {
			insertInSortedList(this->pairs[i].first);
			break;
		}
		if (this->pairs[i].first < this->pairs[i].second){
			insertInSortedList(this->pairs[i].first);
		}
		else {
			insertInSortedList(this->pairs[i].second);
		}
		i++;
	}
}

void PmergeMe::SortWithVector() {
	SortBiggiesList();
	SortSmalliesVec();
}

void PmergeMe::SortWithList() {
	SortBiggiesList();
	SortSmalliesList();
}

void PmergeMe::printVec() {
//	for (int i = 0; i < this->pairAmt; ++i) {
//		std::cout << this->pairs[i].first << ", " << this->pairs[i].second << std::endl;
//	}
	std::cout << "Output:	" ;
	std::vector<int>::iterator it = this->sortedVec->begin();
	while (it != this->sortedVec->end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void PmergeMe::printList() {
	std::cout << "Output;	";
	std::list<int>::iterator it = this->sortedList->begin();
	while (it != this->sortedList->end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}


