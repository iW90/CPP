/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:12:53 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/13 18:18:25 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::~AForm() {}

AForm::AForm() :
	_name("Nameless"),
	_gradeToSign(75),
	_gradeToExecute(75),
	_isSigned(false) {}

AForm::AForm(std::string name, int signGrade, int execGrade) :
	_name(name),
	_gradeToSign(signGrade),
	_gradeToExecute(execGrade),
	_isSigned(false) {
	if (signGrade < HIGHEST_GRADE || execGrade < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (signGrade > LOWEST_GRADE || execGrade > LOWEST_GRADE)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other) :
	_name(other._name),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute) {
	*this = other;
}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other)
		*this = other;
	return (*this);
}

// Getters
const std::string& AForm::getName() const {
	return _name;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

bool AForm::isSigned() const {
	return _isSigned;
}

// Member functions
void AForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign) {
		throw GradeTooLowException();
	}
	else
		this->_isSigned = true;
}

// Exceptions
const char* AForm::GradeTooHighException::what() const throw() {
    return BOLD RED INVERT "Bureaucrat grade is too high." RESET;
}

const char* AForm::GradeTooLowException::what() const throw() {
    return BOLD RED INVERT "Bureaucrat grade is too low." RESET;
}

const char* AForm::FormNotSignedException::what() const throw() {
    return BOLD RED INVERT "Form not signed." RESET;
}

// Non-member function
std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << ITALIC BLUE << form.getName() << ", form is " << (form.isSigned() ? "signed." : "not signed.") << RESET;
    return os;
}
