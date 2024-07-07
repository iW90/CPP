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

Bureaucrat::Bureaucrat() : _name("Nameless"), _grade(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    try {
        if (grade < HIGHEST_GRADE)
            throw GradeTooHighException();
        else if (grade > LOWEST_GRADE)
            throw GradeTooLowException();
        this->_grade = grade;
    } catch (GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    } catch (GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    }
}

Bureaucrat::Bureaucrat(Bureaucrat &other) {
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
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
    try {
        if (grade < HIGHEST_GRADE)
            throw GradeTooHighException();
        else if (grade > LOWEST_GRADE)
            throw GradeTooLowException();
        this->_grade = grade;
    } catch (GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    } catch (GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    }
}

// Member functions
void Bureaucrat::incrementGrade() {
    try {
        if (_grade <= HIGHEST_GRADE)
            throw GradeTooHighException();
        _grade--;
    } catch (std::exception& e) {
        throw;
    }
}

void Bureaucrat::decrementGrade() {
    try {
        if (_grade >= LOWEST_GRADE)
            throw GradeTooLowException();
        _grade++;
    } catch (std::exception& e) {
        throw;
    }
}

// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return BOLD RED INVERT "Error:" RESET " Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return BOLD RED INVERT "Error:" RESET " Grade too low";
}


// Non-member function
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << DIMMED ITALIC YELLOW << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << RESET;
    return os;
}
