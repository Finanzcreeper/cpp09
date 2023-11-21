#include <iostream>
#include "PmergeMe.hpp"
#include <cstring>

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
	PmergeMe sorter(argc - 1, &argv[1]);
	sorter.FillVecWithBiggestOutOfPairs();
	sorter.printVec();
	return (0);
}