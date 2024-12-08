/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:37:24 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/06 11:50:43 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::~Dog() {
	std::cout << "[Dog] Destructor called" << std::endl;
	delete _brain;
}

Dog::Dog() : Animal(), _brain(0) {
	std::cout << "[Dog] Default constructor called" << std::endl;
	setType("Dog");
	_brain = new Brain;
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "[Dog] Copy constructor called" << std::endl;
    _brain = new Brain(*other._brain);
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "[Dog] Assign operator called" << std::endl;
    if (this != &other) {
        setType(other.getType());
        _brain = new Brain(*other._brain);
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
