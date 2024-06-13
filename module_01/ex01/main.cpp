/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:19:42 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/12 22:25:24 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main (void) {
	int N = 10;

	Zombie zomBreeder("Mama Zombie");
	zomBreeder.announce();
	
	Zombie* zumbas = zomBreeder.zombieHorde(N, "Zumbrothers");

	for (int i = 0; i < N; ++i) {
		zumbas[i].announce();
	}
	
	delete[] zumbas;
	
	return 0;
}