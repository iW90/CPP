/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:09:07 by inwagner          #+#    #+#             */
/*   Updated: 2024/11/30 11:54:06 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


static int convertToNumber(char* number) {
    std::stringstream   ss(number);
    int                 num;

    ss >> num;

    if (ss.fail())
        throw std::invalid_argument("Error: NaN");

    if (num < 0)
        throw std::invalid_argument("Error: Not a positive number");
    
    return num;
}

static int* parseArguments(int ac, char** av) {
	if (ac < 2)
		throw std::invalid_argument("nothing to sort");

	int* numbers = new int[ac - 1];
	for (int i = 1; i < ac; i++) {
		try {
			numbers[i - 1] = convertToNumber(av[i]);   
		} catch (std::exception& e) {
			delete[] numbers;
			throw std::invalid_argument(e.what());
		}
	}
	return numbers;
}

static void printContainer(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << "\033[35m" << array[i] << "\t\033[0m";
    }
    std::cout << "\n" << std::endl;
}

int main(int ac, char** av) {
	int* array;
  	int size = ac - 1;

	try {
    	array = parseArguments(ac, av);
	} catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
	}

	std::cout << "\033[36mContainer before:\033[0m" << std::endl;
	printContainer(array, size);

	std::vector<int> vec(array, array + size);
	std::list<int> lst(array, array + size);
	std::deque<int> dqe(array, array + size);


	// PmergeMe<std::vector<int> >::sort(vec);
	std::string vecTime = PmergeMe<std::vector<int> >::timer(PmergeMe<std::vector<int> >::sort, vec, "std::vector");
	std::cout << vecTime << std::endl;
	PmergeMe<std::vector<int> >::is_sorted(vec, "std::vector");

	// PmergeMe<std::list<int> >::sort(lst);
	std::string lstTime = PmergeMe<std::list<int> >::timer(PmergeMe<std::list<int> >::sort, lst, "std::list");
	std::cout << lstTime << std::endl;
	PmergeMe<std::list<int> >::is_sorted(lst, "std::list");
	
	// PmergeMe<std::deque<int> >::sort(dqe);
	std::string dqeTime = PmergeMe<std::deque<int> >::timer(PmergeMe<std::deque<int> >::sort, dqe, "std::deque");
	std::cout << dqeTime << std::endl;
	PmergeMe<std::deque<int> >::is_sorted(dqe, "std::deque");
	
	
	delete[] array;
	return 0;
}

/* Ford Johnson Algorithm (Merge Insertion Sort)
 */


/*
	./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
*/