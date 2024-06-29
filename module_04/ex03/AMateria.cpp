/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:55:46 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/29 10:35:22 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
    //std::cout << "AMateria default constructor is called" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type) {
    //std::cout << "AMateria constructor is called" << std::endl;
}

AMateria::~AMateria() {
    //std::cout << "AMateria destructor is called" << std::endl;
}

AMateria::AMateria(const AMateria& other) {
    //std::cout << "AMateria copy constructor is called" << std::endl;
    *this = other;
}

AMateria& AMateria::operator=(const AMateria & other) {
    //std::cout << "AMateria copy assignment operator overload called" << std::endl;
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

std::string const& AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
    if (this->getType() == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else
		std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}
