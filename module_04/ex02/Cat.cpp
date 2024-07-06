/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:37:33 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/06 11:56:16 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::~Cat() {
    std::cout << "[Cat] Destructor called" << std::endl;
    delete _brain;
}

Cat::Cat() : AAnimal(), _brain(0) {
    std::cout << "[Cat] Default constructor called" << std::endl;
    setType("Cat");
    _brain = new Brain();
}

Cat::Cat(const Cat& other) : AAnimal(other) {
    std::cout << "[Cat] Copy constructor called" << std::endl;
    _brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "[Cat] Assign operator called" << std::endl;
    if (this != &other) {
        setType(other.getType());
        _brain = new Brain(*other._brain);
    }
    return *this;
}

void Cat::makeSound() const {
	std::cout << "Miau" << std::endl;
}

void Cat::setIdea(const std::string idea, int idx) {
    _brain->setIdea(idea, idx);
}

const std::string Cat::getIdea(int idx) const {
    return _brain->getIdea(idx);
}
