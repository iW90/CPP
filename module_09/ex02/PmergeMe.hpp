/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:34:13 by inwagner          #+#    #+#             */
/*   Updated: 2024/11/28 21:23:31 by inwagner         ###   ########.fr       */
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
void printIndex(std::vector<int> indexes);


template<class Container>
class PmergeMe {
    private:
        std::list<int> _groups;


        static void     divider(std::vector<std::pair<int, int> >& messed, std::vector<std::pair<int, int> >& sorted, std::vector<std::pair<int, int> > container_copy);
        static void     ordenate_by_index(std::vector<std::pair<int, int> >& unsorted, std::vector<int>& indexes);
        static void     binary_insert(std::vector<std::pair<int, int> >& sorted, std::vector<std::pair<int, int> >& messed);
        static std::vector<int> extract_indexes(const std::vector<std::pair<int, int> >& unsorted);
        static std::vector<int> recursive_merge(std::vector<std::pair<int, int> >& input);
        
    public:
        ~PmergeMe();
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);




        static void    sort(Container& container);
};

# include "PmergeMe.tpp"



template<class Container>
void PmergeMe<Container>::binary_insert(std::vector<std::pair<int, int> >& sorted, std::vector<std::pair<int, int> >& messed) {
    std::vector<std::pair<int, int> >::const_iterator iter = messed.begin();
    
    while (iter != messed.end()) {
        int lowr = 0;
        int high = sorted.size();

        while (lowr < high) {
            int mid = (lowr + high) / 2;
            if (sorted[mid].first < iter->first)
                lowr = mid + 1;
            else
                high = mid;
        }
        sorted.insert(sorted.begin() + lowr, *(iter++));
    }


}


template<class Container>
void PmergeMe<Container>::ordenate_by_index(std::vector<std::pair<int, int> >& unsorted, std::vector<int>& indexes) {
    std::vector<std::pair<int, int> > temp = unsorted;


    for (size_t i = 0; i < unsorted.size(); i++)
        unsorted[i] = temp[indexes[i]];

    
    printPair(unsorted);

}

template<class Container>
std::vector<int> PmergeMe<Container>::extract_indexes(const std::vector<std::pair<int, int> >& unsorted) {
    std::vector<int> indexes;
    std::vector<std::pair<int, int> >::const_iterator iter = unsorted.begin();

    while (iter != unsorted.end()) {
        indexes.push_back(iter->second);
        iter++;
    }

    return indexes;
}

template<class Container>
std::vector<int> PmergeMe<Container>::recursive_merge(std::vector<std::pair<int, int> >& input) {
    std::vector<int> indexes;

    if (input.size() < 2) {
        indexes = extract_indexes(input);
        return indexes;
    }

    std::vector<std::pair<int, int> > sorted;
    std::vector<std::pair<int, int> > messed;

    divider(messed, sorted, input);

    indexes = recursive_merge(sorted);
    
    ordenate_by_index(sorted, indexes);
    ordenate_by_index(messed, indexes);
    
    indexes.clear();

    binary_insert(messed, sorted);

    indexes = extract_indexes(sorted);

    return indexes;
}

template<class Container>
void PmergeMe<Container>::sort(Container& container) {
    typename Container::const_iterator iter = container.begin();

    std::vector<std::pair<int, int> > container_copy;
    std::vector<int> indexes;

    for (int i = 0; i < (int)container.size() && iter != container.end() ; i++, iter++)
        container_copy.push_back(std::make_pair(*iter, i));


    indexes = recursive_merge(container_copy);

    ordenate_by_index(container_copy, indexes);


    //printPair(container_copy);
    
}




#endif
