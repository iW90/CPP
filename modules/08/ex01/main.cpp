/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 09:33:39 by inwagner          #+#    #+#             */
/*   Updated: 2024/10/06 13:32:33 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "span.hpp"

void fillSpanWithRandomNumbers(Span& sp, unsigned int count) {
    std::set<int>   numbers;
    //int             i = 1;
    
    while (numbers.size() < count)
        numbers.insert((std::rand() % 200000) - 100000);

    for (std::set<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        // std::cout << "[ " << i++ << " ]";
        sp.addNumber(*it);
    }
    //std::cout << std::endl;
}

int main() {
    //main do subject
    std::cout << YELLOW << std::endl;
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    // teste de tamanho máximo e números repetidos
    std::cout << RESET YELLOW << std::endl;        
    {
        try {
            Span sp = Span(5);
            sp.addNumber(0);
            // sp.addNumber(0);
            sp.addNumber(257);
            sp.addNumber(-88);
            sp.addNumber(30);
            sp.addNumber(19);
            // sp.addNumber(19);

            std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
            std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    // teste com 10.000 números aleatórios entre -100.000 e 99.999
    std::cout << RESET YELLOW << std::endl; 
    {
        try {
        std::srand(static_cast<unsigned int>(std::time(0)));
        int sz = 10000;

        Span sp(sz);
        fillSpanWithRandomNumbers(sp, sz);

            std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
            std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << RESET << std::endl; 
    return 0;
}
