#include "RPN.hpp"
#include <iostream>

int main(int argc, char* argv[]){
	if(argc != 2)
	{
		std::cout << "Wrong amount of args!" << std::endl;
		return (1);
	}
	RPN rpn(argv[1]);
	try {
		rpn.calc();
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
}