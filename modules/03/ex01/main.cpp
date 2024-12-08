/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:48:50 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/19 12:21:55 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	{
		ScavTrap scav("Scavando");

		std::cout << "Messages tests" << std::endl;
		scav.attack("Yourself");
		
		scav.attack("");
		scav.takeDamage(-1);
		scav.beRepaired(-1);

		std::cout << std::endl;
		std::cout << "Health Points tests" << std::endl;

		scav.takeDamage(1);
		scav.beRepaired(2);
		scav.takeDamage(11);
		scav.takeDamage(1);

		std::cout << std::endl;
		std::cout << "Energy tests" << std::endl;

		/* setuping for energy tests */
		scav.setEP(0);
		scav.setHP(10);

		scav.attack("You again");
		scav.beRepaired(1);
		scav.attack("A ghost");
		scav.guardGate();
	}
	
	std::cout << std::endl;
	std::cout << "Now is time to fight!!!" << std::endl;
	std::cout << std::endl;
	
	{
		ScavTrap Scaviking("Scaviking");
		ScavTrap Scavenger("Scavenger");

		Scaviking.attack("Scavenger");
		Scavenger.takeDamage(Scaviking.getDamage());
		Scavenger.attack("Scaviking");
		Scaviking.takeDamage(Scavenger.getDamage());
		Scaviking.guardGate();
		Scavenger.guardGate();
		std::cout << "The fight ends because both fighters are in defensive mode..." << std::endl;
	}

  return 0;
}
