/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:34:17 by inwagner          #+#    #+#             */
/*   Updated: 2024/10/12 16:08:34 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int    PmergeMe::_convertToNumber(char* number) {
    std::stringstream   ss(number);
    int                 num;

    ss >> num;

    if (ss.fail())
        throw std::invalid_argument("Error: NaN");

    if (num < 0)
        throw std::invalid_argument("Error: Not a positive number");
    
    return num;
}

void    PmergeMe::_pairParser(int size, char** numbers) {
    for (int i = 1; i < size; i += 2) {
        int num1 = _convertToNumber(numbers[i]);
        int num2 = (i + 1 < size) ? _convertToNumber(numbers[i + 1]) : -1;

        _pairs.push_back(std::make_pair(num1, num2));
    }

}

void    PmergeMe::sort(int size, char** numbers) {
    _pairParser(size, numbers);
    //_sortPairs();



    // Temporário: Exibe os pares ordenados
    for (size_t i = 0; i < _pairs.size(); ++i) {
        std::cout << "Par " << i + 1 << ": (" << _pairs[i].first << ", " << _pairs[i].second << ")" << std::endl;
    }
}








// Orthodox
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
		_pairs = other._pairs;
		_sorted = other._sorted;
    }
    return (*this);
}
