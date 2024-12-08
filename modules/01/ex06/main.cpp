/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:44:42 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/16 18:27:41 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// void testHarl(Harl harl) {
//     std::cout << "Testing Harl with 'debug' level:" << std::endl;
//     harl.complain("debug");

//     std::cout << "\nTesting Harl with 'info' level:" << std::endl;
//     harl.complain("info");

//     std::cout << "\nTesting Harl with 'warning' level:" << std::endl;
//     harl.complain("warning");

//     std::cout << "\nTesting Harl with 'error' level:" << std::endl;
//     harl.complain("error");

//     std::cout << "\nTesting Harl with an unknown level:" << std::endl;
//     harl.complain("unknown");
// }

int main(int ac, char **av) {
	if (ac != 2)
		return 1;
		
    Harl harl;

	harl.complain(av[1]);
	
    return 0;
}
