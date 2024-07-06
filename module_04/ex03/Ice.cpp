/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:08:06 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/06 12:12:17 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	//std::cout << "Ice constructor is called" << std::endl;
}

Ice::~Ice() {
	//std::cout << "Ice destructor is called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {
	//std::cout << "Ice copy constructor is called" << std::endl;
	*this = other;
}

Ice& Ice::operator=(const Ice& other) {
	//std::cout << "Ice copy assignment operator overload called" << std::endl;
    if (this != &other)
		*this = other;
    return (*this);
}

AMateria* Ice::clone() const {
	return (new Ice());
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
