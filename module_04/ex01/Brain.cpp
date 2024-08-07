/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:17:57 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/06 10:51:43 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"

Brain::~Brain() {
    std::cout << "[Brain] Destructor called" << std::endl;
}

Brain::Brain() {
    std::cout << "[Brain] Default constructor called" << std::endl;
    for (int i = 0; i < 100; ++i)
        _ideas[i] = "";
}

Brain::Brain(const Brain& other) {
    std::cout << "[Brain] Copy constructor called" << std::endl;
    for (int i = 0; i < 100; ++i)
        _ideas[i] = other._ideas[i];
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "[Brain] Assign operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; ++i)
            _ideas[i] = other._ideas[i];
    }
    return *this;
}

void Brain::setIdea(const std::string& idea, int idx) {
    if (idx < 0 || idx > 99)
        return;
    _ideas[idx] = idea;
}

const std::string& Brain::getIdea(int idx) const {
    static std::string invalid = "Invalid index";
    if (idx < 0 || idx > 99)
        return invalid;
    return _ideas[idx];
}
