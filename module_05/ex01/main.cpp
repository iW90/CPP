/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:12:44 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/13 16:30:06 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	{
		// Create a form with sign to grade too high: 0
		std::cout << "\nCONSTRUCTING FORM WITH SIGN GRADE 0:" << std::endl;
		try {
			Form formA99("A99", 0, 5);
			std::cout << formA99 << std::endl;
		} catch(std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		// Create form and sign it (without exceptions)
		std::cout << "\nCREATE A FORM AND SIGN IT:" << std::endl;
		try {
			Bureaucrat bea("Beatrice Inkblott", 15);
			Form formB15("B15", 20, 45);
			std::cout << bea << std::endl;
			std::cout << formB15 << std::endl;
			bea.signForm(formB15);
			std::cout << formB15 << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		// Create form and try to sign it but the grade is not enough */
		std::cout << "\nCREATE A FORM AND COULDN'T SIGN IT:" << std::endl;
		try {
			Bureaucrat sally("Sally Signoff", 35);
			Form formS0f("S0F", 20, 45);
			std::cout << sally << std::endl;
			std::cout << formS0f << std::endl;
			sally.signForm(formS0f);
			std::cout << formS0f << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
