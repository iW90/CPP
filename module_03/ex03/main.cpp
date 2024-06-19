/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:48:50 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/19 12:28:28 by inwagner         ###   ########.fr       */
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
	std::cout << "Now is time to fight!!!" << std::endl;
	std::cout << std::endl;
	
	{
		FragTrap freg("Fragmanimus");
		ScavTrap scav("Scavóvisky");
		DiamondTrap dia("Hyoga");
		
		std::cout << "Fragments accept and take double damage from the special electric attack High Five and become paralyzed!" << std::endl;
	}

  return 0;
}
