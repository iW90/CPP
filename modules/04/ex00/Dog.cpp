/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:37:24 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/06 11:05:58 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::~Dog() {
	std::cout << "[Dog] Destructor called" << std::endl;
}

Dog::Dog() : Animal() {
	std::cout << "[Dog] Default constructor called" << std::endl;
	setType("Dog");
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "[Dog] Copy constructor called" << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "[Dog] Assign operator called" << std::endl;
    if (this != &other)
        setType(other.getType());
    return *this;
}

void Dog::makeSound() const {
	std::cout << "AuAu" << std::endl;
}
