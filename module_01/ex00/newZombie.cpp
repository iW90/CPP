/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:35:28 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/11 21:43:53 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
	It creates a zombie, name it, and return it so you can use it outside of the function scope.
*/
Zombie *Zombie::newZombie(std::string name) {
	Zombie* zomb = new Zombie(name);
	zomb->announce();
		
	return zomb;
}
