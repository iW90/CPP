/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:55:46 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/27 19:57:12 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria& other) {
    *this = other;
}

AMateria& AMateria::operator=(const AMateria & other) {
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

std::string const& AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
    target.getName();
}
