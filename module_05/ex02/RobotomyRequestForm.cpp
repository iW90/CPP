/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:03:11 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/13 14:44:36 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm() :
	AForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
	_target(target),
	AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	_target(other._target),
	AForm(other) {
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		*this = other;
	}
	return *this;
}

const std::string& RobotomyRequestForm::getTarget() const {
	return _target;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (!this->isSigned()) {
		throw FormNotSignedException();
		return ;
	} else if (executor.getGrade() > this->getGradeToExecute()) {
		throw GradeTooLowException();
		return ;
	}

	int random = static_cast<int>(std::time(0) % 2);

	if (!random)
		std::cout << GREEN << getName() << " has been robotomized." << RESET << std::endl;
    else
        std::cout << RED << "The robotomy failed." << RESET << std::endl;
}

/*
	• RobotomyRequestForm: Required grades: sign 72, exec 45
	Makes some drilling noises. Then, informs that <target> has been robotomized
	successfully 50% of the time. Otherwise, informs that the robotomy failed.
	
	All of them take only one parameter in their constructor: the target of the form.
*/
