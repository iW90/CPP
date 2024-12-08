#include "ClapTrap.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:48:47 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/18 17:49:22 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::~ClapTrap() {
	std::cout << "[ClapTrap] Destructor called" << std::endl;
}

ClapTrap::ClapTrap() {
	std::cout << "[ClapTrap] Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _energypoints(10), _attackdamage(0) {
	std::cout << "[ClapTrap] Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
		std::cout << "[ClapTrap] Copy constructor called" << std::endl;
		*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "[ClapTrap] Copy assignment operator called" << std::endl;
	
	if (this != &other) {
		this->_name = other._name;
		this->_hitpoints = other._hitpoints;
		this->_energypoints = other._energypoints;
		this->_attackdamage = other._attackdamage;
	}
	return *this;
}

std::string ClapTrap::getName() const {
	return _name;
}

void ClapTrap::setName(std::string& name) {
	_name = name;
}

int ClapTrap::getHP() const {
	return _hitpoints;
}

void ClapTrap::setHP(const int hp) {
	_hitpoints = hp;
}

int ClapTrap::getEP() const {
	return _energypoints;
}

void ClapTrap::setEP(const int ep) {
	_energypoints = ep;
}

int ClapTrap::getDamage() const {
	return _attackdamage;
}

void ClapTrap::setDamage(const int damage) {
	_attackdamage = damage;
}

void ClapTrap::attack(const std::string &target) {
	if (_energypoints < 1) {
		std::cout << "ClapTrap " << _name << " does not have energy points." << std::endl;
		return ;
	}
	if (target.empty()) {
		std::cout << "ClapTrap " << _name << " miss attack." << std::endl;
		return ;
	}
	_energypoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackdamage << " points of damage!" << std::endl;
	return ;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (amount > INT_MAX) {
		std::cout << "You can't take more than " << INT_MAX << " damage or less than 0 damage!" << std::endl;
		return ;
	}
	_hitpoints -= (int)(amount);
	std::cout << "Claptrap " + _name + " has taken " << amount << " damage!" << std::endl;
	if (_hitpoints < 1)
		std::cout << "Claptrap " + _name + " is dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energypoints < 1) {
		std::cout << "ClapTrap " << _name << " does not have energy points." << std::endl;
		return ;
	}
	if (amount > INT_MAX || (_hitpoints + amount) > INT_MAX) {
		std::cout << "You cannot have more than " << INT_MAX << " HP or loose HP during recovery." << std::endl;
		return ;
	}
	_energypoints--;
	_hitpoints += amount;
	std::cout << "ClapTrap " << _name << " recovered " << amount << " points of HP!" << std::endl;
}

