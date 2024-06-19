/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:37:33 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/19 19:45:57 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::~Cat() {}

Cat::Cat() : Animal() {
	setType("Cat");
	std::cout << "[Cat] Default Constructor called" << std::endl;
}

Cat::Cat(Cat &other) {
	*this = other;
}

Cat &Cat::operator=(Cat &other) {
	if (this != &other)
		setType(other.getType());
	return *this;
}

void Cat::makeSound()const {
	std::cout << "Miau" << std::endl;
}
