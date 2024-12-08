/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:48:50 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/19 10:53:26 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
	{
		FragTrap frag("CrazyFrag");

		std::cout << "Messages tests" << std::endl;
		frag.attack("Yourself");
		
		frag.attack("");
		frag.takeDamage(-1);
		frag.beRepaired(-1);

		std::cout << std::endl;
		std::cout << "Health Points tests" << std::endl;

		frag.takeDamage(1);
		frag.beRepaired(2);
		frag.takeDamage(11);
		frag.takeDamage(1);

		std::cout << std::endl;
		std::cout << "Energy tests" << std::endl;

		/* setuping for energy tests */
		frag.setEP(0);
		frag.setHP(10);

		frag.attack("You again");
		frag.beRepaired(1);
		frag.attack("A ghost");
		frag.highFivesGuys();
	}
	
	std::cout << std::endl;
	std::cout << "Now is time to fight!!!" << std::endl;
	std::cout << std::endl;
	
	{
		FragTrap freg("FragMents");
		FragTrap frag("FragTastic");

		freg.attack("FragTastic");
		frag.takeDamage(freg.getDamage());
		frag.highFivesGuys();
		freg.takeDamage(frag.getDamage() * 2);
		std::cout << "Fragments accept and take double damage from the special electric attack High Five and become paralyzed!" << std::endl;
	}

  return 0;
}
