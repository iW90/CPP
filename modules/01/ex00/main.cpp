/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:34:36 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/12 07:41:43 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	// Construtor
	Zombie zomBreeder("Mama Zombie");
	zomBreeder.announce();

	// Memória heap, alocado com new
    Zombie* unDad = zomBreeder.newZombie("Papa Zombie");

	std::cout << "" << std::endl;

	// Memória stack, alocado dinamicamente 
    zomBreeder.randomChump("Zumbebê");

	std::cout << "" << std::endl;

	// Alocação com new requer delete
    delete unDad;

	return 0;
}
