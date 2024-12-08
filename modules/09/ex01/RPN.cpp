/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:33:53 by inwagner          #+#    #+#             */
/*   Updated: 2024/10/12 11:43:07 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool RPN::_validateInput(const char* input) {
    for (int i = 0; input[i] != '\0'; ++i) {
        char c = input[i];
        
        if (!isspace(c) && !isdigit(c) && c != '+' && c != '-' && c != '*' && c != '/')
            return false;
    }
    return true;
}

bool RPN::_isOperator(const char token) {
    return token == '+' || token == '-' || token == '*' || token == '/';
}

int RPN::_calculate(int a, int b, const char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                std::cerr << "Error: Division by zero" << std::endl;
                exit(1);
            }
            return a / b;
        default:
            std::cerr << "Error: Invalid operator" << std::endl;
            exit(1);
    }
}

void RPN::evaluate(const char* input) {
    if (!_validateInput(input)) {
        std::cerr << "Error: Invalid expression" << std::endl;
        exit(1);
    }

    std::stringstream   ss(input);
    std::string         token;

    while (ss >> token) {
        if (_isOperator(token.at(0)) && token.length() == 1) {
            if (_expression.size() < 2) {
                std::cerr << "Error: Insufficient operands" << std::endl;
                exit(1);
            }
            int b = _expression.top(); _expression.pop();
            int a = _expression.top(); _expression.pop();
            int result = _calculate(a, b, token.at(0));
            _expression.push(result);
        } else if (isdigit(token.at(0)) && token.length() == 1) {
            _expression.push(token.at(0) - '0');
        } else {
            std::cerr << "Error: Invalid token '" << token << "'" << std::endl;
            exit(1);
        }
    }

    if (_expression.size() != 1) {
        std::cerr << "Error: Invalid expression" << std::endl;
        exit(1);
    }

    std::cout << _expression.top() << std::endl;
}


// Orthodox
RPN::~RPN() {}

RPN::RPN() {}

RPN::RPN(const RPN &other) {
    *this = other;
}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other)
		_expression = other._expression;
    return (*this);
}
