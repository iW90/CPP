/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:52:20 by inwagner          #+#    #+#             */
/*   Updated: 2024/11/29 23:13:20 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// PmergeMe

template<class Container>
void PmergeMe<Container>::divider(std::vector<std::pair<int, int> >& messed, std::vector<std::pair<int, int> >& sorted, std::vector<std::pair<int, int> > container_copy) {
    std::vector<std::pair<int, int> >::const_iterator iter_next = container_copy.begin();
    std::vector<std::pair<int, int> >::const_iterator iter = iter_next++;

    while (iter != container_copy.end() && iter_next != container_copy.end()) {
        if (iter->first < iter_next->first) {
            messed.push_back(*iter);
            sorted.push_back(*iter_next);
        } else {
            sorted.push_back(*iter);
            messed.push_back(*iter_next);
        }
        iter += 2;
        iter_next += 2;
    }

    if (iter != container_copy.end())
        messed.push_back(*iter);

}


template<class Container>
bool PmergeMe<Container>::is_sorted(const Container& container, const std::string container_name) {
    if (container.size() < 2) return true;

    typename Container::const_iterator next = container.begin();
    typename Container::const_iterator iter = next++;

    while (next != container.end()) {
        if (*iter++ > *next++) {
            std::cerr << "\033[31mContainer " << container_name << " is not sorted\033[0m" << std::endl;
            return false;
        }
    }
    std::cerr << "\033[36mContainer " << container_name << " is sorted\033[0m" << std::endl;
    return true;
}


template<class Container>
Container PmergeMe<Container>::return_values(const std::vector<std::pair<int, int> >& sorted) {
    Container values;
    std::vector<std::pair<int, int> >::const_iterator iter = sorted.begin();

    while (iter != sorted.end()) {
        values.push_back(iter->first);
        iter++;
    }

    return values;
}



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

    for (size_t i = 0; i < indexes.size(); i++)
        unsorted[i] = temp[indexes[i]];
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
void PmergeMe<Container>::insert_indexes(std::vector<std::pair<int, int> >& input) {
    for (int i = 0; i < (int)input.size(); i++)
        input[i].second = i;
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
    std::vector<std::pair<int, int> > sorted_new;
    
    

    divider(messed, sorted, input);
    
    sorted_new = sorted;
    insert_indexes(sorted_new);
    
    indexes = recursive_merge(sorted_new);
    
    ordenate_by_index(sorted, indexes);
    ordenate_by_index(messed, indexes);
    
    indexes.clear();

    binary_insert(sorted, messed);

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

    // printPair(container_copy);

    container = return_values(container_copy);
}



// Utils

// template<class Container>
// void print(Container& container) {
//     typename Container::const_iterator iter = container.begin();

//     while (iter != container.end()) {
//         std::cout << *iter++ << "\t";
//     }
//     std::cout << std::endl;
// }


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
