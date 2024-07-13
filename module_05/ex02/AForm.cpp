/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:12:53 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/13 09:54:39 by inwagner         ###   ########.fr       */
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

const int AForm::getGradeToSign() const {
	return _gradeToSign;
}

const int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

bool AForm::isSigned() const {
	return _isSigned;
}

// Member functions
void AForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign) {
		signForm(bureaucrat, "his grade is too low.");
		throw GradeTooLowException();
	}
	else {
		_isSigned = true;
		signForm(bureaucrat, "");
	}
}

void AForm::signForm(Bureaucrat& bureaucrat, std::string reason) {
	if (this->_isSigned)
		std::cout << GREEN << bureaucrat.getName() << " signed " << this->getName() << "." << RESET << std::endl;
	else
		std::cout << RED << bureaucrat.getName() << " couldn't sign " << this->getName() << " because " << reason << RESET << std::endl;
}

// Exceptions
const char* AForm::GradeTooHighException::what() const throw() {
    return BOLD RED INVERT "Error:" RESET " Bureaucrat grade is too high.";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return BOLD RED INVERT "Error:" RESET " Bureaucrat grade is too low.";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return BOLD RED INVERT "Error:" RESET " Form not signed.";
}

// Non-member function
std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << DIMMED ITALIC YELLOW << form.getName() << ", form is " << (form.isSigned() ? "signed." : "not signed.") << RESET;
    return os;
}
