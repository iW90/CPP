/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:37:33 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/19 20:03:01 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::~Cat() {
	std::cout << "[Cat] Destructor called" << std::endl;
}

Cat::Cat() : Animal() {
	setType("Cat");
	std::cout << "[Cat] Default constructor called" << std::endl;
}

Cat::Cat(Cat &other) : Animal() {
	std::cout << "[Cat] Copy constructor called" << std::endl;
	*this = other;
}

Cat &Cat::operator=(Cat &other) {
	std::cout << "[Cat] Assign operator called" << std::endl;
	if (this != &other)
		setType(other.getType());
	return *this;
}

void Cat::makeSound()const {
	std::cout << "Miau" << std::endl;
}
