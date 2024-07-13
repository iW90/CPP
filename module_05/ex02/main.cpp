/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:04:34 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/13 17:16:00 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {

	// Create the 3 form types
	ShrubberyCreationForm shrubbery("sort");
	RobotomyRequestForm robotomy("Hugh Diligence");
	PresidentialPardonForm pardon("Dilly Dallydelay");
	
	// Create some bureaucrats
	Bureaucrat nina("Nina Neverready", 150);
	Bureaucrat norm("Norman Norms", 120);
	Bureaucrat manny("Manny Mandate", 3);
	
	{
		// Attempt to execute forms without being signed
		std::cout << "\nATTEMPT TO EXECUTE UNSIGNED FORMS:" << std::endl;
		try {
			std::cout << nina << std::endl;
			
			std::cout << "\t- Forms status:" << std::endl;
			std::cout << shrubbery << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;
			
			std::cout << "\t- Nina attempts to execute unsigned forms:" << std::endl;
			nina.executeForm(shrubbery);
			nina.executeForm(robotomy);
			nina.executeForm(pardon);
			
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	
	{
		// Sign form and attempt to execute without sufficient grade
		std::cout << "\nATTEMPT TO EXECUTE FORMS WITH INSUFFICIENT GRADE:" << std::endl;
		try {
			std::cout << nina << std::endl;
			std::cout << norm << std::endl;
			
			std::cout << "\t- Form before signing:" << std::endl;
			std::cout << shrubbery << std::endl;
			
			shrubbery.beSigned(norm);
			std::cout << "\t- Form signed by Norm:" << std::endl;
			std::cout << shrubbery << std::endl;
			
			std::cout << "\t- Nina does not have the required grade to execute the form:" << std::endl;
			nina.executeForm(shrubbery);
			
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		// Sign forms and execute them
		std::cout << "\nSIGN AND EXECUTE FORMS:" << std::endl;
		try {
			robotomy.beSigned(manny);
			pardon.beSigned(manny);

			std::cout << "\t- Forms status after signing:" << std::endl;
			std::cout << shrubbery << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;
			
			std::cout << "\n\t- Manny Mandate executes forms:" << std::endl;
			manny.executeForm(shrubbery);
			std::cout << "" << std::endl;
			manny.executeForm(robotomy);
			std::cout << "" << std::endl;
			manny.executeForm(pardon);
			std::cout << "" << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	return (0);
}
