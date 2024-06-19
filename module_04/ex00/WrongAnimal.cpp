/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:31:10 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/19 20:04:46 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::~WrongAnimal() {
	std::cout << "[WrongAnimal] Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal() {
	setType("WrongAnimal");
	std::cout << "[WrongAnimal] Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal& other) : WrongCat() {
	std::cout << "[WrongAnimal] Copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal& other) {
	std::cout << "[WrongAnimal] Assign operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

void WrongAnimal::makeSound()const {
	std::cout << "AuAu" << std::endl;
}
