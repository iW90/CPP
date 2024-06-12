/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:35:21 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/11 21:43:57 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
	It creates a zombie, name it, and the zombie announces itself.
*/
void Zombie::randomChump(std::string name) {
	Zombie zomb(name);
	zomb.announce();
}
