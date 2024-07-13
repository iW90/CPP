/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:13:03 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/09 17:00:06 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string 	_name;
		const int 			_gradeToSign;
		const int			_gradeToExecute;
		bool 				_isSigned;

	protected:
		AForm();

	public:
		virtual ~AForm();
		AForm(std::string name, int signGrade, int execGrade);
		AForm(AForm& other);
		AForm& operator=(const AForm& other);

		const std::string& 		getName() const;
		const int 				getGradeToSign() const;
		bool 					isSigned() const;

		void 					beSigned(Bureaucrat& bureaucrat);
		void 					signForm(Bureaucrat& bureaucrat, std::string reason);
		virtual void 			execute(const Bureaucrat& executor) const = 0;
	
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

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif