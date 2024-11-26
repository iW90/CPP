/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:09:07 by inwagner          #+#    #+#             */
/*   Updated: 2024/11/25 21:32:06 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int convertToNumber(char* number) {
    std::stringstream   ss(number);
    int                 num;

    ss >> num;

    if (ss.fail())
        throw std::invalid_argument("Error: NaN");

    if (num < 0)
        throw std::invalid_argument("Error: Not a positive number");
    
    return num;
}

int* parseArguments(int ac, char** av) {
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

int main(int ac, char** av) {
	int* array;
  	int size = ac - 1;

	try {
    	array = parseArguments(ac, av);
	} catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
	}


	std::vector<int> vec(array, array + size);
	std::list<int> lst(array, array + size);

	PmergeMe<std::vector<int> >::sort(vec);
	PmergeMe<std::list<int> >::sort(lst);
	

	
	delete[] array;
	return 0;
}

/* Ford Johnson Algorithm (Merge Insertion Sort)
 * 
 *
 * 
 * 
 * 
 * 
 * 
 */
