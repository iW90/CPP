/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:31:10 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/19 19:48:24 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::~WrongAnimal() {}

WrongAnimal::WrongAnimal() {
	setType("WrongAnimal");
	std::cout << "[WrongAnimal] Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal& other) {
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal& other) {
	if (this != &other)
		_type = other._type;
	return *this;
}

void WrongAnimal::makeSound()const {
	std::cout << "Au Au" << std::endl;
}
