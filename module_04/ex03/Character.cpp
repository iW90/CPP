/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:16:26 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/06 14:15:03 by inwagner         ###   ########.fr       */
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
	for(int i = 0; i < 10; i++)
		this->_trash[i] = NULL;
}

Character::~Character() {
	//std::cout << "Character destructor is called" << std::endl;
	for(int i = 0; i < 4; i++) {
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
	for(int i = 0; i < 10; i++) {
		if (this->_trash[i] != NULL)
			delete this->_trash[i];
	}
}

Character::Character(const Character& other) {
	//std::cout << "Character copy constructor is called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		for(int i = 0; i < 4; i++)
			this->_inventory[i] = (other._inventory[i] != NULL) ? other._inventory[i]->clone() : NULL;
		for(int i = 0; i < 10; i++)
			this->_trash[i] = (other._trash[i] != NULL) ? other._trash[i]->clone() : NULL;
	}
	*this = other;
}

Character& Character::operator=(const Character& other) {
	//std::cout << "Character copy assignment operator overload called" << std::endl;
	if (this != &other) {
		this->_name = other.getName();
        for (int i = 0; i < 4; ++i) {
            AMateria* newInventory = (other._inventory[i] != NULL) ? other._inventory[i]->clone() : NULL;
            delete this->_inventory[i];
            this->_inventory[i] = newInventory;
        }
		for (int i = 0; i < 10; ++i) {
            AMateria* newTrash = (other._trash[i] != NULL) ? other._trash[i]->clone() : NULL;
            delete this->_trash[i];
            this->_trash[i] = newTrash;
        }
	}
	return (*this);
}

std::string const & Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria* m) {
	if (!m) {
		std::cout << this->_name << " tried to equip nothing and it did nothing." << std::endl;
		return ;
	}
	for (int i = 0; i < 4; ++i) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			std::cout << this->_name << " equipped materia " << m->getType() << " in slot " << i << std::endl;

			for (int i = 0; i < 10; ++i) {
				if (this->_trash[i] == m)
					this->_trash[i] = NULL;
			}
			
			return ;
		}
	}
	std::cout << "Character: " << this->getName() << " has a full _inventory!" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4)
		std::cout << this->_name << " tried to unequip nothing at slot " << idx << " and it did nothing." << std::endl;
	else if (!(this->_inventory)[idx])
		std::cout << this->_name << " has nothing equipped at slot " << idx << " so he can't unequip it." << std::endl;
	else {
		for (int i = 0; i < 10; ++i) {
			if (this->_trash[i] == NULL) {
				this->_trash[i] = (this->_inventory)[idx];
				this->_inventory[idx] = NULL;
				std::cout << this->_name << " unequip " << _trash[i]->getType() << " from slot "<< idx << std::endl;
				return ;
			}
		}
		std::cout << "Can't unequip. Trash is full." << std::endl;
	}
}

void Character::use(int idx, ICharacter& target) {
	if ((idx > 0 || idx <= 4) && _inventory[idx] != NULL)
		this->_inventory[idx]->use(target);
	else
		std::cout << "Unable to use." << std::endl;
}
