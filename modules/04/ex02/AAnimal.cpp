/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:34:13 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/06 11:34:16 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::~AAnimal() {
	std::cout << "[AAnimal] Destructor called" << std::endl;
}

AAnimal::AAnimal() : _type("AAnimal") {
	std::cout << "[AAnimal] Default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) {
    *this = other;
	std::cout << "[AAnimal] Copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	std::cout << "[AAnimal] Assign operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

std::string AAnimal::getType() const {
	return _type;
}

void AAnimal::setType(std::string type) {
	_type = type;
}

void AAnimal::makeSound() const {
	std::cout << "AAnimal Sound" << std::endl;
}
