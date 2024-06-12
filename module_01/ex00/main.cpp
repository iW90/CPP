/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:34:36 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/11 21:46:39 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	// Construtor
	Zombie zombieCreator("Papa Zombie");

	// Memória heap, alocado com new
    Zombie* zombieBaby = zombieCreator.newZombie("Zumbebê");

	std::cout << "\n" << std::endl;

	// Memória stack, alocado dinamicamente 
    Zombie zombieBrother("Zombão");
    zombieBrother.randomChump("Zombão");

	std::cout << "\n" << std::endl;

	// Alocação com new requer delete
    delete zombieBaby;

	return 0;
}
