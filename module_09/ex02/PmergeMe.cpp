/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:34:17 by inwagner          #+#    #+#             */
/*   Updated: 2024/11/25 22:10:54 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"



// Utils

void printPair(std::vector<std::pair<int, int> > contCopy) {
    std::vector<std::pair<int, int> >::const_iterator iter = contCopy.begin();

    while (iter != contCopy.end()) {
        std::cout << iter->first << "-" << iter->second << "\t";
        iter++;
    }
    std::cout << std::endl;
}
