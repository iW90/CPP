/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:10:58 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/29 12:03:28 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	//std::cout << "MateriaSource constructor is called" << std::endl;
	this->_idx = 0;
	for (int i = 0; i < 4; i++)
		this->_memory[i] = NULL;
}

MateriaSource::~MateriaSource() {
	//std::cout << "MateriaSource destructor is called" << std::endl;
	for(int i = 0; i < 4; i++) {
		if(this->_memory[i] != NULL)
			delete this->_memory[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	//std::cout << "MateriaSource copy constructor is called" << std::endl;
	*this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	//std::cout << "MateriaSource copy assignment operator overload called" << std::endl;
    if (this != &other)
		*this = other;
    return (*this);
}

void MateriaSource::learnMateria(AMateria* materia) {
	for(int i = 0; i < 4; i++) {
		if(this->_memory[i] == NULL) {
			this->_memory[i] = materia;
			this->_idx = i;
			//std::cout << "New materia of type: " << materia->getType() << " in index: " << this->_idx << std::endl;
			break;
		}
	}
}

AMateria* MateriaSource::getMateria(unsigned int _idx) {
	if (_idx < 4 && _idx <= this->_idx)
		return (this->_memory[_idx]);
	return (0);
}

AMateria** MateriaSource::getMaterias() {
	return (this->_memory);
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	if(type != "ice" && type != "cure") {
		//std::cout << "The type: " << type << " is unknown!" << std::endl;
		return (0);
	}
	else {
		for(int i = 3; i > -1; i--) {
			if(getMateria(i) != 0 && getMateria(i)->getType() == type) {
				AMateria* newMateria;
				if(type == "ice")
					newMateria = new Ice();
				else
					newMateria = new Cure();
				return (newMateria);
			}
		}
		//std::cout << "The materia of type: " << type << " doesn't exist in the learning _memory" << std::endl;
		return (0);
	}
}
