/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:48:50 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/24 08:56:36 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void) {
	{
		DiamondTrap frag("Hyoga");

		std::cout << "Messages tests" << std::endl;
		frag.attack("Yourself");
		
		frag.attack("");
		frag.FragTrap::takeDamage(-1);
		frag.ScavTrap::beRepaired(-1);

		std::cout << std::endl;
		std::cout << "Health Points tests" << std::endl;

		frag.ScavTrap::takeDamage(1);
		frag.FragTrap::beRepaired(2);
		frag.FragTrap::takeDamage(11);
		frag.ScavTrap::takeDamage(1);

		std::cout << std::endl;
		std::cout << "Energy tests" << std::endl;

		/* setuping for energy tests */
		frag.ScavTrap::setEP(0);
		frag.FragTrap::setHP(10);

		frag.attack("You again");
		frag.FragTrap::beRepaired(1);
		frag.attack("A ghost");
		frag.whoAmI();
	}
	
	std::cout << std::endl;
	std::cout << "Now is time to fight!!!\n" << std::endl;
	std::cout << std::endl;
	
	{
		ClapTrap clap("Claperson");
		FragTrap freg("Fragmanimus");
		ScavTrap scav("Scavóvisky");
		DiamondTrap diad("Hyoga");

		std::cout << "\n" << std::endl;

		clap.attack("Claperson");
		freg.attack("Fragmanimus");
		scav.attack("Scavóvisky");
		diad.attack("Hyoga");

		std::cout << "\n" << std::endl;
		
		clap.takeDamage(500);
		freg.takeDamage(500);
		scav.takeDamage(500);
		diad.takeDamage(500);
		
		std::cout << "\nThe initial mold came with a factory defect, and now all the Traps are experiencing a short circuit.\n" << std::endl;
	}

  return 0;
}
