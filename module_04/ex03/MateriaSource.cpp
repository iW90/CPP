/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:10:58 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/27 19:15:48 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i)
        templates[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const & other) {
    for (int i = 0; i < 4; ++i)
        templates[i] = other.templates[i] ? other.templates[i]->clone() : 0;
}

MateriaSource& MateriaSource::operator=(MateriaSource const & other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            delete templates[i];
            templates[i] = other.templates[i] ? other.templates[i]->clone() : 0;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i)
        delete templates[i];
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (!templates[i]) {
            templates[i] = m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (templates[i] && templates[i]->getType() == type)
            return templates[i]->clone();
    }
    return 0;
}
