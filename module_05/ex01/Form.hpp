/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:13:03 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/09 16:55:22 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Form {
	private:
		const std::string 	_name;
		const int 			_gradeToSign;
		bool 				_isSigned;

	protected:
		Form();

	public:
		~Form();
		Form(std::string name, int grade);
		Form(Form& other);
		Form& operator=(const Form& other);

		const std::string& 	getName() const;
		const int 			getGradeToSign() const;
		bool 				isSigned() const;

		void 				beSigned(Bureaucrat& bureaucrat);
		void 				signForm(Bureaucrat& bureaucrat, std::string reason);
	
		// Exceptions Classes
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
    	class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif