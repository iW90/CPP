/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:02:43 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/13 14:44:56 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		const std::string _target;

	protected:
		ShrubberyCreationForm();

	public:
		~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	
		const std::string&	getTarget() const;

		void 				execute(const Bureaucrat& executor) const;
		
		static std::string	_binaryTree();

		// Exceptions Classes
		class FileOpenException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif
