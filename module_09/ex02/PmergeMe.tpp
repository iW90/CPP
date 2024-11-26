/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:52:20 by inwagner          #+#    #+#             */
/*   Updated: 2024/11/25 22:12:22 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// PmergeMe

template<class Container>
void PmergeMe<Container>::divider(std::vector<std::pair<int, int> >& lower, std::vector<std::pair<int, int> >& upper, std::vector<std::pair<int, int> > contCopy) {
    std::vector<std::pair<int, int> >::const_iterator iter_next = contCopy.begin();
    std::vector<std::pair<int, int> >::const_iterator iter = iter_next++;
    int i = 0;

    while (iter != contCopy.end() && iter_next != contCopy.end()) {
        if (iter->first < iter_next->first) {
            lower.push_back(std::make_pair(iter->first, i));
            upper.push_back(std::make_pair(iter_next->first, i));
        } else {
            upper.push_back(std::make_pair(iter->first, i));
            lower.push_back(std::make_pair(iter_next->first, i));      
        }
        i++;
        iter += 2;
        iter_next += 2;
    }

    if (iter != contCopy.end())
        lower.push_back(std::make_pair(iter->first, i));
}


// Utils

template<class Container>
void print(Container& container) {
    typename Container::const_iterator iter = container.begin();

    while (iter != container.end()) {
        std::cout << *iter++ << "\t";
    }
    std::cout << std::endl;
}


// Orthodox

template<class Container>
PmergeMe<Container>::~PmergeMe() {}

template<class Container>
PmergeMe<Container>::PmergeMe() {}

template<class Container>
PmergeMe<Container>::PmergeMe(const PmergeMe &other) {
    *this = other;
}

template <class Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(const PmergeMe& other) {
  if (this != &other) {
    _groups = other._groups;
  }
  return *this;
}
