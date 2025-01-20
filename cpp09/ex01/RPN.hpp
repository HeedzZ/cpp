#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <stdexcept>

class RPN {
public:
    RPN(const std::string& expression);
	~RPN();
    int evaluate();

private:
    std::string _expression;

    bool isOperator(char c) const;
    int performOperation(int a, int b, char op) const;

	RPN();
	RPN(const RPN& other);
    RPN& operator=(const RPN& other);
};

#endif
