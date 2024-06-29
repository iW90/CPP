/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:07:51 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/29 12:01:38 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	//std::cout << "Cure constructor is called" << std::endl;
}

Cure::~Cure() {
	//std::cout << "Cure destructor is called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
	//std::cout << "Cure copy constructor is called" << std::endl;
	*this = other;
}

Cure& Cure::operator=(const Cure& other) {
	//std::cout << "Cure copy assignment operator overload called" << std::endl;
    if (this != &other)
		*this = other;
    return (*this);
}

AMateria* Cure::clone() const {
	return (new Cure());
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}
