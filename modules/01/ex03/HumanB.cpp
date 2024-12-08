/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 11:13:22 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/16 14:12:45 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

std::string HumanB::getName(void) const {
	return _name;
}

void HumanB::setName(std::string name) {
	_name = name;
}

Weapon& HumanB::getWeapon(void) const {
	return *_weapon;
}

void HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
}


void HumanB::attack(void) {
	std::cout << _name;
	std::cout << " attacks with their ";
	if (_weapon)
		std::cout << _weapon->getType() << std::endl;
	else
		std::cout << "punches" << std::endl;
}
