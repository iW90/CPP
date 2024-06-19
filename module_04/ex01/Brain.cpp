/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:17:57 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/19 20:35:41 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"


Brain::~Brain() {
	std::cout << "[Brain] Destructor called" << std::endl;
}

Brain::Brain() {
	std::cout << "[Brain] Default constructor called" << std::endl;
}

Brain::Brain(Brain& other) {
    *this = other;
	std::cout << "[Brain] Copy constructor called" << std::endl;
}

Brain& Brain::operator=(Brain& other) {
	std::cout << "[Brain] Assign operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            _ideas[i] = other._ideas[i];
        }
    }
    return *this;
}