/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:51:03 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/09 13:33:36 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	{
		// Constructor with a bad grade		
		// -49
		std::cout << "\nCONSTRUCTING WITH GRADE -300:" << std::endl;
		try {
			Bureaucrat bill("Bill", -300);
		} catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << e.what();
		}

		// 256
		std::cout << "\nCONSTRUCTING WITH GRADE 300:" << std::endl;
		try {
			Bureaucrat bill("Bill", 300);
		} catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << e.what();
		}
	}

	Bureaucrat bob("Bob", 1);

	{
		// Normal increment/decrement and "<<" overload
		std::cout << "\nIN/DECREMENT + << overload:" << std::endl;
		try {
			bob.decrementGrade();
		} catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << e.what();
		}
		// "<<" operator overload used / Grade should be 2
		std::cout << bob << std::endl;
		
		try {
			bob.incrementGrade();
		} catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << e.what();
		}
		// "<<" operator overload used / Grade should be 1
		std::cout << bob << std::endl;
	}
	{
		// Increment 1 exception
		std::cout << "\nINCREMENT GRADE 1:" << std::endl;
		try {
			bob.incrementGrade();
		} catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << e.what();
		}
		std::cout << "" << std::endl;

		// Decrement 150 exception
		std::cout << "\nDECREMENT GRADE 150:" << std::endl;
		bob.setGrade(150);
		try {
			bob.decrementGrade();
		} catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << e.what();
		}
		std::cout << "\n" << std::endl;
	}
	
	return (0);
}
