/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:34:13 by inwagner          #+#    #+#             */
/*   Updated: 2024/12/08 10:27:06 by inwagner         ###   ########.fr       */
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
# include <ctime>
# include <cmath>
# include <iomanip>
# include <utility>

void printIndex(std::vector<int> indexes);
void printPair(std::vector<std::pair<int, int> > container_copy);

template<class Container>
class PmergeMe {
    private:
        static void     print(Container& container);
        static void     divider(std::vector<std::pair<int, int> >& messed, std::vector<std::pair<int, int> >& sorted, std::vector<std::pair<int, int> > container_copy);
        static void     ordenate_by_index(std::vector<std::pair<int, int> >& unsorted, std::vector<int>& indexes);
        static void     insert_indexes(std::vector<std::pair<int, int> >& input);
        static void     insert_partitions(std::vector<std::pair<int, int> >& sorted, const std::vector<std::pair<int, int> >& messed);
        static void     binary_insert(std::vector<std::pair<int, int> >& sorted, std::pair<int, int> pair, int max);
        static int      get_next_partition(int previous, int current);
        static std::vector<int> extract_indexes(const std::vector<std::pair<int, int> >& unsorted);
        static std::vector<int> recursive_merge(std::vector<std::pair<int, int> >& input);
        static Container discard_indexes(const std::vector<std::pair<int, int> >& sorted);

    public:
        ~PmergeMe();
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);

        static void         sort(Container& container);
        static bool         is_sorted(const Container& container, const std::string container_name);
        static std::string  timer(void (*sortFunc)(Container&), Container& container, const char* container_type);
};

# include "PmergeMe.tpp"


#endif
