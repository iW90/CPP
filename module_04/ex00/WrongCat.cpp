/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:31:03 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/19 19:58:34 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::~WrongCat() {
	std::cout << "[WrongCat] Destructor called" << std::endl;
}

WrongCat::WrongCat() : _type("WrongCat") {
	setType("WrongCat");
	std::cout << "[WrongCat] Default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat &other) {
	std::cout << "[WrongCat] Copy constructor called" << std::endl;
	*this = other;
}

WrongCat &WrongCat::operator=(WrongCat &other) {
	std::cout << "[WrongCat] Assign operator called" << std::endl;
	if (this != &other)
		setType(other.getType());
	return *this;
}

std::string WrongCat::getType() const {
	return _type;
}

void WrongCat::setType(std::string type) {
	_type = type;
}

void WrongCat::makeSound()const {
	std::cout << "Muuu" << std::endl;
}
