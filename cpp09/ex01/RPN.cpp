#include "RPN.hpp"
#include <sstream>
#include <cstdlib>

RPN::RPN() : _expression("") {}

RPN::RPN(const std::string& expression) : _expression(expression) {}

RPN::RPN(const RPN& other) : _expression(other._expression) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _expression = other._expression;
    }
    return *this;
}

RPN::~RPN() {}


bool RPN::isOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::performOperation(int a, int b, char op) const {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0)
                throw std::runtime_error("Division by zero");
            return a / b;
        default:
            throw std::invalid_argument("Invalid operator");
    }
}

int RPN::evaluate() {
    std::stack<int> stack;
    std::istringstream stream(_expression);
    std::string token;

    while (stream >> token) {
        if (token.size() == 1 && isOperator(token[0])) {
            if (stack.size() < 2)
                throw std::runtime_error("Invalid expression");
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            stack.push(performOperation(a, b, token[0]));
        } else {
            char* end;
            int number = std::strtol(token.c_str(), &end, 10);
            if (*end != '\0')
                throw std::runtime_error("Invalid token: " + token);
            stack.push(number);
        }
    }

    if (stack.size() != 1)
        throw std::runtime_error("Invalid expression");

    return stack.top();
}
