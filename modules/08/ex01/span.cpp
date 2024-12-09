/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 09:33:59 by inwagner          #+#    #+#             */
/*   Updated: 2024/12/09 16:06:32 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span() {}

Span::~Span() {}

Span::Span(unsigned int num) : _maxSize(num) {}

Span::Span(const Span& other) {
	*this = other;
}

Span &Span::operator=(const Span &other) {
    if (this != &other)
		_maxSize = other._maxSize;
        _numbers = other._numbers;
    return (*this);
}

//add a single number to the Span. It will be used in order to fill it.
void Span::addNumber(int number) {
    if (_numbers.size() >= this->_maxSize)
        throw std::out_of_range("Cannot add more numbers, span is full.");
    _numbers.insert(number);
}

//Find out the shortest span
int Span::shortestSpan() {
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span.");

    std::vector<int> differences;
    std::set<int>::const_iterator start = _numbers.begin();
    std::set<int>::const_iterator final = _numbers.end();
    std::adjacent_difference(start, final, std::back_inserter(differences));
    return *std::min_element(differences.begin() + 1, differences.end());
}

//Find out the longest span
int Span::longestSpan() {
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span.");

    return *(_numbers.rbegin()) - *(_numbers.begin());
}



/* Dado que um set é ordenado:
 *    set = {1, 3, 4, 6, 9}
 *      Entre 1 e 3:  2
 *      Entre 3 e 4:  1
 *      Entre 4 e 6:  2
 *      Entre 6 e 9:  3
 *
 *    - Maior span:
 *        A maior diferença será sempre entre o menor e o maior número,
 *        ou seja, entre o primeiro e o último número.
 *        A maior diferença é 8, entre 1 e 9.
 *
 *    - Menor span:
 *        Requer que seja iterado o set para encontrar a menor diferença.
 *        A menor diferença é 1, entre 3 e 4.
 */