/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:34:13 by inwagner          #+#    #+#             */
/*   Updated: 2024/10/12 16:08:07 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <utility>
# include <sstream>
# include <stdexcept>
# include <algorithm>

class PmergeMe {
    private:
        std::vector<std::pair<int, int> >   _pairs;
        std::deque<int>                     _sorted;

        int    _convertToNumber(char* number);
        void   _pairParser(int size, char** numbers);
        
    public:
        ~PmergeMe();
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);

        void    sort(int size, char** numbers);
    
};

#endif