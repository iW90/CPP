/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:02:50 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/13 18:00:04 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
	AForm("ShrubberyCreationForm", 145, 137),
	_target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
	AForm(other),
	_target(other._target) {
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		*this = other;
	}
	return *this;
}

const std::string& ShrubberyCreationForm::getTarget() const {
	return _target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (!this->isSigned()) {
		throw FormNotSignedException();
		return ;
	} else if (executor.getGrade() > this->getGradeToExecute()) {
		throw GradeTooLowException();
		return ;
	}

	std::string fileName = _target + "_shrubbery";

	// Abrir o arquivo de saída
	std::ofstream outputFile; 
    outputFile.open(fileName.c_str(), std::ios::out);
    if (!outputFile) {
        throw FileOpenException();
        return ;
    }

    outputFile << _binaryTree(); // Escrever a string modificada no arquivo de saída
    outputFile.close();
	
	std::cout << GREEN << fileName << " has been created." << RESET << std::endl;
}

std::string ShrubberyCreationForm::_binaryTree() {
    std::string tree =
        "        ______10______\n"
        "       /              \\\n"
        "    __5__           __15__\n"
        "   /     \\         /      \\\n"
        "  2       7       12      20\n"
        " / \\     / \\     /  \\    /  \\\n"
        "1   3   6   8   11  13  18  25\n";

    return tree;
}

// Exceptions
const char* ShrubberyCreationForm::FileOpenException::what() const throw() {
    return BOLD RED INVERT "File not created." RESET;
}

/*
	• ShrubberyCreationForm: Required grades: sign 145, exec 137
	Create a file <target>_shrubbery in the working directory, and writes ASCII trees
	inside it.
	
	All of them take only one parameter in their constructor: the target of the form. For
	example, "home" if you want to plant shrubbery at home.
*/
