/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:37:24 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/06 10:27:04 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::~Dog() {
	std::cout << "[Dog] Destructor called" << std::endl;
	delete _brain;
}

Dog::Dog() : Animal() {
	std::cout << "[Dog] Default constructor called" << std::endl;
	setType("Dog");
	_brain = new Brain;
}

Dog::Dog(Dog &other) : Animal(other) {
	std::cout << "[Cat] Copy constructor called" << std::endl;
	*this = other;
}

Dog &Dog::operator=(Dog &other) {
	std::cout << "[Dog] Assign operator called" << std::endl;
	if (this != &other) {
		setType(other.getType());
		*_brain = *other._brain;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "AuAu" << std::endl;
}

void Dog::setIdea(const std::string idea, int idx) {
    _brain->setIdea(idea, idx);
}

const std::string Dog::getIdea(int idx) const {
    return _brain->getIdea(idx);
}
