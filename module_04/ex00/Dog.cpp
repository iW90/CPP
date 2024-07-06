/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:37:24 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/06 08:57:42 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::~Dog() {
	std::cout << "[Dog] Destructor called" << std::endl;
}

Dog::Dog() : Animal() {
	setType("Dog");
	std::cout << "[Dog] Default constructor called" << std::endl;
}

Dog::Dog(Dog &other) : Animal(other) {
	std::cout << "[Cat] Copy constructor called" << std::endl;
	*this = other;
}

Dog &Dog::operator=(Dog &other) {
	std::cout << "[Dog] Assign operator called" << std::endl;
	if (this != &other)
		setType(other.getType());
	return *this;
}

void Dog::makeSound() const {
	std::cout << "AuAu" << std::endl;
}
