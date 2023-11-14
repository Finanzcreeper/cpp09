
#ifndef CPP09_RPN_HPP
#define CPP09_RPN_HPP

#include <stack>
#include <exception>
#include <string>

class RPN
{
private:
	std::stack<int> rpn;
	std::string input;
public:
	RPN(const std::string&);
	RPN(const RPN& src);

	~RPN();

	RPN& operator=(const RPN& src);

	void calc();
	void base_op(int *a, int *b);

	class syntaxERR : public std::exception
	{
	private:
	public:
		const char * what() const throw();
	};
	class dbz : public std::exception
	{
	public:
		const char * what() const throw();
	};
};
#endif //CPP09_RPN_HPP
