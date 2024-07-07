/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:33:56 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/07 18:15:59 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

# define HIGHEST_GRADE 		1
# define LOWEST_GRADE 		150

//Colors
# define RESET         		"\033[0m"
# define BOLD          		"\033[1m"
# define ITALIC				"\033[3m"
# define INVERT				"\033[7m"
# define RED           		"\033[31m"
# define GREEN         		"\033[32m"
# define YELLOW        		"\033[33m"
# define BLUE	          	"\033[34m"
# define DIMMED				"\033[2m"

class Bureaucrat {
	private:
		const std::string 	_name;
		int 				_grade;

	protected:
		Bureaucrat();
		
	public:
		~Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);

		const std::string& 	getName() const;
		int 				getGrade() const;
		void 				setGrade(int grade);

		void 				incrementGrade();
		void 				decrementGrade();

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif