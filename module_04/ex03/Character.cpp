/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:16:26 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/05 19:05:48 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {
	//std::cout << "Character default constructor is called" << std::endl;
}

Character::Character( std::string const & name ) {
	//std::cout << "Character constructor is called" << std::endl;
	this->_name = name;
	for(int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	this->_idx = 0;
}

Character::~Character() {
	//std::cout << "Character destructor is called" << std::endl;
	for(int i = 0; i < 4; i++) {
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
}

Character::Character(const Character& other) {
	//std::cout << "Character copy constructor is called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_idx = other._idx;
		for(int i = 0; i < 4; i++)
			this->_inventory[i] = (other._inventory[i] != NULL) ? other._inventory[i]->clone() : NULL;
	}
	*this = other;
}

Character& Character::operator=(const Character& other) {
	//std::cout << "Character copy assignment operator overload called" << std::endl;
	if (this != &other) {
		this->_name = other.getName();
		this->_idx = other._idx;
        for (int i = 0; i < 4; ++i) {
            AMateria* newMateria = (other._inventory[i] != NULL) ? other._inventory[i]->clone() : NULL;
            delete this->_inventory[i];
            this->_inventory[i] = newMateria;
        }
	}
	return (*this);
}

std::string const & Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria* m) {
	if (!m) {
		std::cout << this->_name << " tried to equip nothing and it did nothing\n";
		return ;
	}
	if (this->_idx < 4) {
		this->_inventory[this->_idx] = m;
		std::cout << this->_name << " equipped materia " << m->getType() << " in slot " << _idx << "\n";
		this->_idx++;
	}
	else
		std::cout << "Character: " << this->getName() << " has a full _inventory!\n";
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4)
		std::cout << this->_name << " tried to unequip nothing at slot " << idx << " and it did nothing\n";
	else if (!(this->_inventory)[idx])
		std::cout << this->_name << " has nothing equipped at slot " << idx << " so he can't unequip it\n";
	else {
		AMateria *ptr = (this->_inventory)[idx];
		this->_inventory[idx] = NULL;
		std::cout << this->_name << " unequipped " << ptr->getType() << " at slot "<< idx << "\n";
	}
}

void Character::use(int _idx, ICharacter& target) {
	if (_idx > -1 && _idx < 4 && _idx <= this->_idx)
		this->_inventory[_idx]->use(target);
	else
		std::cout << "The index is wrong\n";
}
