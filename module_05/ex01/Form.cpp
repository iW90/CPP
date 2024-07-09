/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:12:53 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/09 16:57:08 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::~Form() {}

Form::Form() : _name("Nameless"), _isSigned(false), _gradeToSign(75) {}

Form::Form(std::string name, int grade) : _name(name), _isSigned(false), _gradeToSign(grade) {
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
}

Form::Form(Form& other) : _name(other._name), _gradeToSign(other._gradeToSign) {
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

const int Form::getGradeToSign() const {
	return _gradeToSign;
}

bool Form::isSigned() const {
	return _isSigned;
}

// Member functions
void Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign) {
		signForm(bureaucrat, "his grade is too low.");
		throw GradeTooLowException();
	}
	else
		_isSigned = true;
}

void Form::signForm(Bureaucrat& bureaucrat, std::string reason) {
	if (this->_isSigned)
		std::cout << GREEN << bureaucrat.getName() << " signed " << this->getName() << "." << RESET << std::endl;
	else
		std::cout << RED << bureaucrat.getName() << " couldn't sign " << this->getName() << " because " << reason << RESET << std::endl;
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw() {
    return BOLD RED INVERT "Error:" RESET " Bureaucrat grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return BOLD RED INVERT "Error:" RESET " Bureaucrat grade is too low";
}

// Non-member function
std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << DIMMED ITALIC YELLOW << form.getName() << ", form is " << (form.isSigned() ? "signed." : "not signed.") << RESET;
    return os;
}
