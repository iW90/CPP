/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:23:04 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/12 22:21:43 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

// Destrutor
Zombie::~Zombie() {
	std::cout << _name << " is dead-dead." << std::endl;
}

Zombie::Zombie(const std::string& name) : _name(name) {}

Zombie::Zombie() {};

// Get e Set
std::string Zombie::getName() {
	return _name;
}

void Zombie::setName(std::string &name) {
	_name = name;
}

void Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

