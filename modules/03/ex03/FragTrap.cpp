/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 08:43:48 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/23 11:19:56 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::~FragTrap() {
	std::cout << "[FragTrap] Destructor called" << std::endl;
}

FragTrap::FragTrap() {
	std::cout << "[FragTrap] Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	setHP(100);
	setEP(100);
	setDamage(30);
	std::cout << "[FragTrap] Default Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "[FragTrap] Copy Constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "[FragTrap] Copy assignment operator called" << std::endl;
	
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}


void FragTrap::attack(const std::string &target) {
	if (getEP() < 1) {
		std::cout << "FragTrap " << getName() << " does not have energy points." << std::endl;
		return ;
	}
	if (target.empty()) {
		std::cout << "FragTrap " << getName() << " miss attack." << std::endl;
		return ;
	}
	setEP(getEP() - 1);
	std::cout << "FragTrap " << getName() << " attacks " << target << ", causing " << getDamage() << " points of damage!" << std::endl;
	return ;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << getName() << " is offering an electrifying high five to everyone!" << std::endl;
}
