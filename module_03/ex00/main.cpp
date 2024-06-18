/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:48:50 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/18 18:42:50 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
	ClapTrap blip("Marvin");

	std::cout << "\nMessages tests" << std::endl;
	blip.attack("You");
	blip.attack("");
	blip.takeDamage(-1);
	blip.beRepaired(-1);

	std::cout << std::endl;
	std::cout << "\nHealth Points tests" << std::endl;

	blip.takeDamage(1);
	blip.beRepaired(2);
	blip.takeDamage(11);
	blip.takeDamage(1);

	std::cout << std::endl;
	std::cout << "Energy tests" << std::endl;

	/* setuping for energy tests */
	blip.setEP(0);
	blip.setHP(10);

	blip.attack("You again");
	blip.beRepaired(1);
	blip.attack("A ghost");

	return EXIT_SUCCESS;
}