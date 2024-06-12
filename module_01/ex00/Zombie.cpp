/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:34:49 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/11 21:44:02 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor
Zombie::Zombie(const std::string& name) : _name(name) {}

// Destrutor
Zombie::~Zombie() {
	std::cout << _name << " is dead-dead." << std::endl;
}

// Get e Set
std::string Zombie::getName() {
	return _name;
}

void Zombie::setName(std::string &name) {
	_name = name;
}


// Features

/*
	Zombies announce themselves as follows: <name>: BraiiiiiiinnnzzzZ...
*/
void Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


