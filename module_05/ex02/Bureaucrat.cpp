#include "Bureaucrat.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:33:53 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/07 13:33:54 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat() :
    _name("Nameless"),
    _grade(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : 
    _name(name),
    _grade(grade) {
    if (grade < HIGHEST_GRADE)
        throw GradeTooHighException();
    else if (grade > LOWEST_GRADE)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other)
		*this = other;
    return (*this);
}

// Getters and setters
const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::setGrade(int grade) {
    if (grade < HIGHEST_GRADE)
        throw GradeTooHighException();
    else if (grade > LOWEST_GRADE)
        throw GradeTooLowException();
    else
        this->_grade = grade;
}

// Member functions
void Bureaucrat::incrementGrade() {
    if (_grade <= HIGHEST_GRADE)
        throw GradeTooHighException();
    else
        _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= LOWEST_GRADE)
        throw GradeTooLowException();
    else
        _grade++;
}

void Bureaucrat::signForm(AForm& form) {

    try {
        form.beSigned(*this);
		std::cout << GREEN << _name << " signed " << form.getName() << "." << RESET << std::endl;
    } catch (std::exception& e) {
		std::cout << RED << _name << " couldn't sign " << form.getName() << " because " <<  e.what() << RESET << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm& form) {
	if (_grade <= form.getGradeToSign()) {
        form.execute(*this);
		std::cout << GREEN << _name << " executed " << form.getName() << "." << RESET << std::endl;
    }
	else
		std::cout << RED << _name << " couldn't execute " << form.getName() << "." << RESET << std::endl;
}

// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return BOLD RED INVERT "Grade too high." RESET;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return BOLD RED INVERT "Grade too low." RESET;
}


// Non-member function
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << ITALIC BLUE << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << RESET;
    return os;
}
