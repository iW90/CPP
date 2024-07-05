/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:31:10 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/29 17:13:26 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::~WrongAnimal() {
	std::cout << "[WrongAnimal] Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << "[WrongAnimal] Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal& other) {
	std::cout << "[WrongAnimal] Copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal& other) {
	std::cout << "[WrongAnimal] Assign operator called" << std::endl;
	if (this != &other)
		setType(other.getType());
	return *this;
}

std::string WrongAnimal::getType() const {
	return _type;
}

void WrongAnimal::setType(std::string type) {
	_type = type;
}

void WrongAnimal::makeSound()const {
	std::cout << "zzz" << std::endl;
}
