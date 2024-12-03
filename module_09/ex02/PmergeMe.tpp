/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:52:20 by inwagner          #+#    #+#             */
/*   Updated: 2024/12/02 21:06:11 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
  return *this;
}


// Utils
template<class Container>
void PmergeMe<Container>::print(Container& container) {
    typename Container::const_iterator iter = container.begin();

    while (iter != container.end()) {
        std::cout << *iter++ << "\t";
    }
    std::cout << std::endl;
}

template <typename Container>
std::string PmergeMe<Container>::timer(void (*sortFunc)(Container&), Container& container, const char* container_type) {
    std::ostringstream output;

    // output << "Sorting container of type: " << container_type << std::endl;

    clock_t start = clock();
    sortFunc(container);
    clock_t end = clock();

    double duration = double(end - start) / CLOCKS_PER_SEC;

    // Exibir o tempo em milissegundos
    output << "\033[36mTime taken for sort '"
            << container_type 
            << "': "
            << std::fixed << std::setprecision(4) 
            << duration * 1000 << " ms\t\033[0m";  // Convertendo para milissegundos

    return output.str();
}

template<class Container>
bool PmergeMe<Container>::is_sorted(const Container& container, const std::string container_name) {
    if (container.size() < 2) return true;

    typename Container::const_iterator next = container.begin();
    typename Container::const_iterator iter = next++;

    std::cout << "\033[34mContainer " << container_name << " after:\033[0m" << std::endl;
    while (next != container.end()) {
        std::cout << "\033[33m" << *iter << "\t\033[0m";
        if (*iter++ > *next++) {
            std::cerr << "\033[31mContainer " << container_name << " is not sorted\033[0m" << std::endl;
            return false;
        }
    }
    std::cout << "\033[33m" << *iter << "\n\033[0m" << std::endl;
    return true;
}

// PmergeMe

// main function
template<class Container>
void PmergeMe<Container>::sort(Container& container) {
    typename Container::const_iterator iter = container.begin();

    std::vector<std::pair<int, int> > container_copy;
    std::vector<int> indexes;
    std::vector<int> partition;

    partition = create_partition_sizes(container.size());


    for (int i = 0; i < (int)container.size() && iter != container.end() ; i++, iter++)
        container_copy.push_back(std::make_pair(*iter, i));


    indexes = recursive_merge(container_copy, partition);

    ordenate_by_index(container_copy, indexes);

    container = return_values(container_copy);
}

// aux functions
template<class Container>
std::vector<int> PmergeMe<Container>::recursive_merge(std::vector<std::pair<int, int> >& input, const std::vector<int> partition) {
    std::vector<int> indexes;

    if (input.size() < 2) {
        indexes = extract_indexes(input);
        return indexes;
    }
    (void)partition;
    std::vector<std::pair<int, int> > sorted;
    std::vector<std::pair<int, int> > messed;
    std::vector<std::pair<int, int> > sorted_new;
    
    divider(messed, sorted, input);
    
    sorted_new = sorted;
    insert_indexes(sorted_new);
    
    indexes = recursive_merge(sorted_new, partition);
    
    ordenate_by_index(sorted, indexes);
    ordenate_by_index(messed, indexes);
    
    indexes.clear();

    binary_insert(sorted, messed);

    indexes = extract_indexes(sorted);

    return indexes;
}


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
std::vector<int, std::pair<int, int> > PmergeMe<Container>::generate_partition(std::vector<std::pair<int, int> >& messed, std::vector<int> partition) {
    std::vector<std::pair<int, int> >::const_iterator iter = messed.begin();
    std::vector<std::pair<int, int>, int> indexed_partition;

    int i = 0;

    
    return indexed_partition;
}


template<class Container>
std::vector<int> PmergeMe<Container>::create_partition_sizes(int container_size) {
    std::vector<int> partition;
    
    if (container_size == 0)
        return partition;

    partition.push_back(2);
    if (container_size == 1)
        return partition;

    
    int i = 2, sum = 2;

    while (true) {
        int next_value = std::pow(2, i) - partition[i - 2];
        if (sum + next_value <= container_size) {
            partition.push_back(next_value);
            sum += next_value;
            i++;
        } else {
            if (container_size - sum ) partition.push_back(container_size - sum);
            break;
        }
    }
    return partition;
}


template<class Container>
void PmergeMe<Container>::insert_indexes(std::vector<std::pair<int, int> >& input) {
    for (int i = 0; i < (int)input.size(); i++)
        input[i].second = i;
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
