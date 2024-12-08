/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:15:35 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/13 17:41:57 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

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

class Intern {
    typedef AForm* (*FormCreator)(std::string);
	
    struct FormMap {
        std::string formName;
        FormCreator formCreator;
    };

	public:
		~Intern();
		Intern();
		Intern(const Intern& other);
		const Intern& operator=(const Intern& other);

		AForm* makeForm(std::string formName, std::string target);

		static AForm* createPresidentialPardonForm(std::string target);
		static AForm* createRobotomyRequestForm(std::string target);
		static AForm* createShrubberyCreationForm(std::string target);

		//Exceptions
		class InvalidFormException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif