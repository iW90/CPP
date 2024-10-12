/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:33:50 by inwagner          #+#    #+#             */
/*   Updated: 2024/10/12 12:07:24 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <stack>
# include <string>
# include <cstdlib>

class RPN {
    private:
        std::stack<int> _expression;
        
        int     _calculate(int a, int b, char op);
        bool    _validateInput(const char* input);
        bool    _isOperator(const char token);

    public:
        ~RPN();
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);

        void    evaluate(const char* input);
};


#endif