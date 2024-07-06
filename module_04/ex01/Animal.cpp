/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:34:13 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/06 10:59:13 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::~Animal() {
	std::cout << "[Animal] Destructor called" << std::endl;
}

Animal::Animal() : _type("Animal") {
	std::cout << "[Animal] Default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
    *this = other;
	std::cout << "[Animal] Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << "[Animal] Assign operator called" << std::endl;
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

void Animal::makeSound() const {
	std::cout << "Animal Sound" << std::endl;
}
