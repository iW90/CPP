/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:34:13 by inwagner          #+#    #+#             */
/*   Updated: 2024/11/24 22:02:10 by inwagner         ###   ########.fr       */
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

template<class Container>
class PmergeMe {
    private:
        std::list<int> _groups;


        
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

    while (iter != container.end()) {
        std::cout << *iter++ << "\t";
    }
    std::cout << std::endl;

    
}


#endif
