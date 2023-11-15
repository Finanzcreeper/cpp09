#include "btc.hpp"

int main (int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Wrong number of args!" << std::endl;
		return (1);
	}
	btc(argv[1]);
}