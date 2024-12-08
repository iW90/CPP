/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:24:49 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/16 18:30:12 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void testHarl() {
    Harl harl;
    std::cout << "Testing Harl with 'debug' level:" << std::endl;
    harl.complain("DEBUG");

    std::cout << "\nTesting Harl with 'info' level:" << std::endl;
    harl.complain("INFO");

    std::cout << "\nTesting Harl with 'warning' level:" << std::endl;
    harl.complain("WARNING");

    std::cout << "\nTesting Harl with 'error' level:" << std::endl;
    harl.complain("ERROR");

    std::cout << "\nTesting Harl with an unknown level:" << std::endl;
    harl.complain("I am not sure how tired I am today...");
}

int main() {
    testHarl();
    return 0;
}

