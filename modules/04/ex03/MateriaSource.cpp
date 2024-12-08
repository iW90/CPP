/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:10:58 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/06 14:07:14 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::~MateriaSource() {
	//std::cout << "MateriaSource destructor is called" << std::endl;
	for(int i = 0; i < 4; i++) {
		if(this->_memory[i] != NULL) {
			delete this->_memory[i];
			_memory[i] = NULL;
		}
	}
}

MateriaSource::MateriaSource() {
	//std::cout << "MateriaSource constructor is called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_memory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	//std::cout << "MateriaSource copy constructor is called" << std::endl;
	if (this != &other) {
    	for(int i = 0; i < 4; i++) {
			if(this->_memory[i] != NULL) {
				delete this->_memory[i];
				_memory[i] = NULL;
			}
			_memory[i] = other._memory[i]->clone();
		}
	}
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
			std::cout << "New materia of type: " << materia->getType() << " in index: " << i << std::endl;
			return ;
		}
	}
}

AMateria* MateriaSource::getMateria(int idx) const {
	if (idx < 0 || idx >= 4)
		return (0);
	return (this->_memory[idx]);
}

AMateria* MateriaSource::createMateria(const std::string& type) {
	if(type != "ice" && type != "cure") {
		std::cout << "The type: " << type << " is unknown!" << std::endl;
		return (0);
	}
	for (int i = 0; i < 4; i++) {
		if (_memory[i] != NULL && _memory[i]->getType() == type)
			return _memory[i]->clone();
	}
	std::cout << "The materia of type: " << type << " doesn't exist in the learning _memory" << std::endl;
	return NULL;
}
