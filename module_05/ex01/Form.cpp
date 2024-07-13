/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:12:53 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/13 16:28:17 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::~Form() {}

Form::Form() :
	_name("Nameless"),
	_gradeToSign(75),
	_gradeToExecute(75),
	_isSigned(false) {}

Form::Form(std::string name, int signGrade, int execGrade) :
	_name(name),
	_gradeToSign(signGrade),
	_gradeToExecute(execGrade),
	_isSigned(false) {
	if (signGrade < HIGHEST_GRADE || execGrade < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (signGrade > LOWEST_GRADE || execGrade > LOWEST_GRADE)
		throw GradeTooLowException();
}

Form::Form(const Form& other) :
	_name(other._name),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute) {
	*this = other;
}

Form &Form::operator=(const Form &other) {
	if (this != &other)
		*this = other;
	return (*this);
}

// Getters
const std::string& Form::getName() const {
	return _name;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

bool Form::isSigned() const {
	return _isSigned;
}

// Member functions
void Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign) {
		throw GradeTooLowException();
	}
	else
		this->_isSigned = true;
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw() {
    return BOLD RED INVERT "Error:" RESET " Bureaucrat grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return BOLD RED INVERT "Error:" RESET " Bureaucrat grade is too low";
}

const char* Form::FormNotSignedException::what() const throw() {
    return BOLD RED INVERT "Error:" RESET " Form not signed.";
}

// Non-member function
std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << DIMMED ITALIC YELLOW << form.getName() << ", form is " << (form.isSigned() ? "signed." : "not signed.") << RESET;
    return os;
}
