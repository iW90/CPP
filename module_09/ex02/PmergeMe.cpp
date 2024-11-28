/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:34:17 by inwagner          #+#    #+#             */
/*   Updated: 2024/11/27 21:24:49 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"



// Utils

void printPair(std::vector<std::pair<int, int> > container_copy) {
    std::vector<std::pair<int, int> >::const_iterator iter = container_copy.begin();

    while (iter != container_copy.end()) {
        std::cout << iter->first << "-" << iter->second << "\t";
        iter++;
    }
    std::cout << std::endl;
}
