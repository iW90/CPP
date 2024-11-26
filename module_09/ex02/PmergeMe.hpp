/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:34:13 by inwagner          #+#    #+#             */
/*   Updated: 2024/11/25 22:13:27 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <list>
# include <utility>
# include <sstream>
# include <stdexcept>
# include <algorithm>

void printPair(std::vector<std::pair<int, int> > contCopy);


template<class Container>
class PmergeMe {
    private:
        std::list<int> _groups;


        static void    divider(std::vector<std::pair<int, int> >& lower, std::vector<std::pair<int, int> >& upper, std::vector<std::pair<int, int> > contCopy);
        
    public:
        ~PmergeMe();
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);




        static void    sort(Container& container);
};

# include "PmergeMe.tpp"







template<class Container>
void PmergeMe<Container>::sort(Container& container) {
    typename Container::const_iterator iter = container.begin();

    std::vector<std::pair<int, int> > contCopy;
    std::vector<std::pair<int, int> > upper;
    std::vector<std::pair<int, int> > lower;

    for (int i = 0; i < (int)container.size() && iter != container.end() ; i++, iter++)
        contCopy.push_back(std::make_pair(*iter, i));

    printPair(contCopy);

    divider(lower, upper, contCopy);
    std::cout << "Lower: ";
    printPair(lower);
    std::cout << "Upper: ";
    printPair(upper);
    std::cout << std::endl;


    
}




#endif
