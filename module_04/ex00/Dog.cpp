/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:37:24 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/19 19:46:03 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::~Dog() {}

Dog::Dog() : Animal() {
	setType("Dog");
	std::cout << "[Dog] Default Constructor called" << std::endl;
}

Dog::Dog(Dog &other) {
	*this = other;
}

Dog &Dog::operator=(Dog &other) {
	if (this != &other)
		setType(other.getType());
	return *this;
}

void Dog::makeSound()const {
	std::cout << "Au Au" << std::endl;
}
