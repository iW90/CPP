/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:34:17 by inwagner          #+#    #+#             */
/*   Updated: 2024/11/30 11:09:47 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// 
// void printPair(std::vector<std::pair<int, int> > contCopy);
// void printIndex(std::vector<int> indexes);

// Utils

void printPair(std::vector<std::pair<int, int> > container_copy) {
    std::vector<std::pair<int, int> >::const_iterator iter = container_copy.begin();

    while (iter != container_copy.end()) {
        std::cout << iter->first << "-" << iter->second << "\t";
        iter++;
    }
    std::cout << std::endl;
}

void printIndex(std::vector<int> indexes) {
    std::vector<int>::const_iterator iter = indexes.begin();

    while (iter != indexes.end()) {
        std::cout << *iter << "\t";
        iter++;
    }
    std::cout << std::endl;
}


