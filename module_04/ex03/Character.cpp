/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:16:26 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/27 19:53:03 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(std::string const & name) : name(name) {
    for (int i = 0; i < 4; ++i)
        inventory[i] = 0;
}

Character::Character(Character const & other) : name(other.name) {
    for (int i = 0; i < 4; ++i)
        inventory[i] = other.inventory[i] ? other.inventory[i]->clone() : 0;
}

Character& Character::operator=(Character const & other) {
    if (this != &other) {
        name = other.name;
        for (int i = 0; i < 4; ++i) {
            delete inventory[i];
            inventory[i] = other.inventory[i] ? other.inventory[i]->clone() : 0;
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; ++i)
        delete inventory[i];
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (!inventory[i]) {
            inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4)
        inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx]->use(target);
}
