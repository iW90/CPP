/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:15:30 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/13 17:43:40 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::~Intern() {}

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    *this = other;
}

const Intern &Intern::operator=(const Intern &other) {
    if (this != &other)
		*this = other;
    return (*this);
}

AForm *Intern::makeForm(std::string form, std::string target)
{
	FormMap formMap[] = {
		{"PresidentialPardonForm", &createPresidentialPardonForm},
		{"RobotomyRequestForm", &createRobotomyRequestForm},
		{"ShrubberyCreationForm", &createShrubberyCreationForm}
	};

    int formCount = sizeof(formMap) / sizeof(FormMap);

    for (int i = 0; i < formCount; ++i) {
        if (formMap[i].formName == form) {
            return ((formMap[i].formCreator))(target);
        }
    }

    throw InvalidFormException();
    return NULL;
}

AForm* Intern::createPresidentialPardonForm(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomyRequestForm(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubberyCreationForm(std::string target) {
    return new ShrubberyCreationForm(target);
}

const char* Intern::InvalidFormException::what() const throw() {
    return BOLD RED INVERT "Error:" RESET " Invalid form.";
}
