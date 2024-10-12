/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:09:07 by inwagner          #+#    #+#             */
/*   Updated: 2024/10/12 16:06:45 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char** av) {
    if (ac < 2) {
        std::cerr << "Error: No list provided" << std::endl;
        return 1;
    }

	try {
		PmergeMe pmm;
		pmm.sort(ac, av);
		return 0;
	} catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
	}
	return 0;
}
