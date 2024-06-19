/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:03:22 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/19 12:19:34 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::~DiamondTrap() {
	std::cout << "[DiamondTrap] Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap() {
	std::cout << "[DiamondTrap] Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name), FragTrap(name), ScavTrap(name) {
	FragTrap::setHP(FragTrap::getHP());
	ScavTrap::setEP(ScavTrap::getEP());
	FragTrap::setDamage(FragTrap::getDamage());
	_name = name + "_Diamond";
	std::cout << "[DiamondTrap] Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ScavTrap(other), FragTrap(other) {
	std::cout << "[DiamondTrap] Copy Constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << "[DiamondTrap] Copy assignment operator called" << std::endl;
	
	if (this != &other) {
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		_name = other._name;
	}
	return *this;
}


std::string DiamondTrap::getName() const {
	return _name;
}

void DiamondTrap::setName(std::string& name) {
	_name = name;
}


void DiamondTrap::attack(const std::string &target) {
	if (ScavTrap::getEP() < 1) {
		std::cout << "DiamondTrap " << ScavTrap::getName() << " does not have energy points." << std::endl;
		return ;
	}
	if (target.empty()) {
		std::cout << "DiamondTrap " << ScavTrap::getName() << " misses attack." << std::endl;
		return ;
	}
	ScavTrap::setEP(ScavTrap::getEP() - 1);
	std::cout << "DiamondTrap " << ScavTrap::getName() << " attacks " << target << ", causing " << FragTrap::getDamage() << " points of damage!" << std::endl;
	return ;
}

void DiamondTrap::whoAmI() {
	std::cout << "I am DiamondTrap " << getName() << FragTrap::getName() << "!" << std::endl;
}
