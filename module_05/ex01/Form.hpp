/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:13:03 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/13 16:28:02 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string 	_name;
		const int 			_gradeToSign;
		const int			_gradeToExecute;
		bool 				_isSigned;

	protected:
		Form();

	public:
		~Form();
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);

		const std::string& 	getName() const;
		int 				getGradeToSign() const;
		int 				getGradeToExecute() const;
		bool 				isSigned() const;

		void 				beSigned(Bureaucrat& bureaucrat);
	
		// Exceptions Classes
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
    	class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif