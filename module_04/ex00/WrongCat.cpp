/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:31:03 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/29 17:12:54 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::~WrongCat() {
	std::cout << "[WrongCat] Destructor called" << std::endl;
}

WrongCat::WrongCat() {
	setType("WrongCat");
	std::cout << "[WrongCat] Default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat &other) : WrongAnimal() {
	std::cout << "[WrongCat] Copy constructor called" << std::endl;
	*this = other;
}

WrongCat &WrongCat::operator=(WrongCat &other) {
	std::cout << "[WrongCat] Assign operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

void WrongCat::makeSound()const {
	std::cout << "Miau" << std::endl;
}
