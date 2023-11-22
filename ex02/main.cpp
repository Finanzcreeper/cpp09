#include <iostream>
#include "PmergeMe.hpp"
#include <ctime>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Wrong number of args" << std::endl;
		return (1);
	}
	int c(0);
	for (int i = 1; i < argc; ++i) {
		c = 0;
		while (argv[i][c]) {
			if (std::isdigit(argv[i][c++]) == false) {
				std::cout << "Non Number input!" << std::endl;
				return (2);
			}
		}
	}
	std::cout << "Input:	";
	for (int i = 1; i < argc; ++i) {
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "---VECTOR----" << std::endl;
	clock_t Vstart = clock();
	PmergeMe Vsorter(argc - 1, &argv[1]);
	Vsorter.SortWithVector();
	Vsorter.printVec();
	clock_t Vend = clock();
	std::cout << "Sorting "<< argc - 1 <<" elements with a vector took: " << Vend - Vstart << " μs" << std::endl;

	std::cout << "---LIST----" << std::endl;
	clock_t Lstart = clock();
	PmergeMe Lsorter(argc - 1, &argv[1]);
	Lsorter.SortBiggiesVec();
	Lsorter.printVec();
	clock_t Lend = clock();
	std::cout << "Sorting "<< argc - 1 <<" elements with a list took: " << Lend - Lstart << " μs" << std::endl;

	return (0);
}