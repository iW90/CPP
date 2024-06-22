/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:23:17 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/22 14:14:16 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int N, std::string name)
{
	if (N < 1)
		return NULL;
		
	Zombie* zumbas = new Zombie[N];

	for (int i = 0; i < N; ++i) {
		new (&zumbas[i]) Zombie(name);
	}

	return zumbas;
}
