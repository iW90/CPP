/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:03:25 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/13 16:58:06 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm() :
	AForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
	AForm("PresidentialPardonForm", 25, 5),
	_target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
	AForm(other),
	_target(other._target) {
	*this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		*this = other;
	}
	return *this;
}

const std::string& PresidentialPardonForm::getTarget() const {
	return _target;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (!this->isSigned()) {
		throw FormNotSignedException();
		return ;
	} else if (executor.getGrade() > this->getGradeToExecute()) {
		throw GradeTooLowException();
		return ;
	} else
		std::cout << GREEN << _target << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}

/*
	• PresidentialPardonForm: Required grades: sign 25, exec 5
	Informs that <target> has been pardoned by Zaphod Beeblebrox.
	
	All of them take only one parameter in their constructor: the target of the form.
*/
