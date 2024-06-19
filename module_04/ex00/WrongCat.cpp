/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:31:03 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/19 19:48:39 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::~WrongCat() {}

WrongCat::WrongCat() : _type("WrongCat") {
	setType("WrongCat");
	std::cout << "[WrongCat] Default Constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat &other) {
	*this = other;
}

WrongCat &WrongCat::operator=(WrongCat &other) {
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
	std::cout << "Mu" << std::endl;
}
