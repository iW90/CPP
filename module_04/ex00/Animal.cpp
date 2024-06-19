/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:34:13 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/19 19:44:57 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::~Animal() {}

Animal::Animal() : _type("Animal") {}

Animal::Animal(Animal& other) {
    *this = other;
}

Animal& Animal::operator=(Animal& other) {
	if (this != &other)
		_type = other._type;
	return *this;
}

std::string Animal::getType() const {
	return _type;
}

void Animal::setType(std::string type) {
	_type = type;
}

void Animal::makeSound()const {
	std::cout << "" << std::endl;
}
