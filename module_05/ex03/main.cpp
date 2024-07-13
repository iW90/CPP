/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:06:56 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/13 17:56:00 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern		newman;
	AForm		*form;
	Bureaucrat	betty("Betty Bureaucraft", 5);

	{
		// Create forms, and the last one does not exists.
		std::cout << "\nCREATE FORMS:" << std::endl;
		try {
			form = newman.makeForm("PresidentialPardonForm", "Ollie Overform");
			std::cout << *form << std::endl;
			delete form;
			
			form = newman.makeForm("RobotomyRequestForm", "Penny Paperstack");
			std::cout << *form << std::endl;
			delete form;
			
			form = newman.makeForm("ShrubberyCreationForm", "machine_learning");
			std::cout << *form << std::endl;
			delete form;
			
			form = newman.makeForm("RandomForm", "Wendy Formfairy");
			std::cout << *form << std::endl;
			delete form;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		// Test forms
		std::cout << "\nTEST CREATED FORMS:" << std::endl;
		try {
			std::cout << "\t- Newman create Shrubbery Form:" << std::endl;
			form = newman.makeForm("ShrubberyCreationForm", "diretories");
			betty.signForm(*form);
			betty.executeForm(*form);
			delete form;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		
		try {
			std::cout << "\t- Newman create Presidential Pardon Form:" << std::endl;
			form = newman.makeForm("PresidentialPardonForm", "Rudy Redtape");
			betty.signForm(*form);
			betty.executeForm(*form);
			delete form;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		try {
			std::cout << "\t- Newman create Robotomy Request Form:" << std::endl;
			form = newman.makeForm("RobotomyRequestForm", "Barry Formsmith");
			betty.signForm(*form);
			betty.executeForm(*form);
			delete form;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	
	return (0);
}