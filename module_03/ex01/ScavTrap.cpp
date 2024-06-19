/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:23:53 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/19 09:40:32 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::~ScavTrap() {
	std::cout << "[ScavTrap] Destructor called" << std::endl;
}

ScavTrap::ScavTrap() {
	std::cout << "[ScavTrap] Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	setHP(100);
    setEP(50);
    setDamage(20);
	_guardMode = false;
	std::cout << "[ScavTrap] Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    _guardMode = other._guardMode;
    std::cout << "[ScavTrap] Copy Constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "[ScavTrap] Copy assignment operator called" << std::endl;
	
	if (this != &other) {
		ClapTrap::operator=(other);
		_guardMode = other._guardMode;
	}
	return *this;
}


bool ScavTrap::isGuardMode()const {
	return _guardMode;
}

void ScavTrap::setGuardMode(bool mode) {
	_guardMode = mode;
}


void ScavTrap::attack(const std::string &target) {
	if (getEP() < 1) {
		std::cout << "ScavTrap " << getName() << " does not have energy points." << std::endl;
		return ;
	}
	if (target.empty()) {
		std::cout << "ScavTrap " << getName() << " miss attack." << std::endl;
		return ;
	}
	setEP(getEP() - 1);
	std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getDamage() << " points of damage!" << std::endl;
	return ;
}

void ScavTrap::guardGate() {
	_guardMode = !_guardMode;
	std::cout << "ScavTrap " << getName() << " now in Gate Keeper Mode" << std::endl;
}
