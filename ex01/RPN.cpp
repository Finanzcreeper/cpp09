#include "RPN.hpp"
#include <stack>
#include <iostream>
#include <string>

RPN::RPN(const std::string& in) : input(in)
{}

RPN::RPN(const RPN &src) : rpn(src.rpn), input(src.input)
{}

RPN::~RPN()
{}

RPN &RPN::operator=(const RPN &src) {
	this->input = src.input;
	this->rpn = src.rpn;
	return *this;
}

void RPN::calc() {
	int a(0);
	int b(0);
	std::string::iterator it = this->input.begin();

	while (it != this->input.end()) {
		if (isdigit(*it)) {
			this->rpn.push(*it - '0');
		}
		else if (*it == '+') {
			this->base_op(&a,&b);
			this->rpn.push(a + b);
		}
		else if (*it == '-') {
			this->base_op(&a,&b);
			this->rpn.push(a - b);
		}
		else if (*it == '*') {
			this->base_op(&a,&b);
			this->rpn.push(a * b);
		}
		else if (*it == '/') {
			this->base_op(&a,&b);
			if (b == 0) {
				throw dbz();
			}
			this->rpn.push(a / b);
		}
		else if (*it != ' ')
			throw syntaxERR();
		++it;
	}
	if (this->rpn.size() != 1){
		throw syntaxERR();
	}
	std::cout << this->rpn.top() << std::endl;
}

void RPN::base_op(int *a, int *b) {
	if (this->rpn.size() != 2)
		throw syntaxERR();
	*b = this->rpn.top();
	this->rpn.pop();
	*a = this->rpn.top();
	this->rpn.pop();
}

const char *RPN::syntaxERR::what() const throw() {
	return "Syntax Error";
}

const char *RPN::dbz::what() const throw() {
	return "Division by 0 disallowed";
}

