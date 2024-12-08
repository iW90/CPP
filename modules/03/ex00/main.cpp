/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:48:50 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/19 08:12:40 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
	ClapTrap clap("Clapinator");

	std::cout << "\nMessages tests" << std::endl;
	clap.attack("You");
	clap.attack("");
	clap.takeDamage(-1);
	clap.beRepaired(-1);

	std::cout << std::endl;
	std::cout << "\nHealth Points tests" << std::endl;

	clap.takeDamage(1);
	clap.beRepaired(2);
	clap.takeDamage(11);
	clap.takeDamage(1);

	std::cout << std::endl;
	std::cout << "Energy tests" << std::endl;

	/* setuping for energy tests */
	clap.setEP(0);
	clap.setHP(10);

	clap.attack("You again");
	clap.beRepaired(1);
	clap.attack("A ghost");

	return 0;
}