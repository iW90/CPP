/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:30:53 by inwagner          #+#    #+#             */
/*   Updated: 2024/09/06 20:06:54 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <exception>
# include <cctype>
# include <sstream> 

class ScalarConverter {
	private:
		ScalarConverter();
        ~ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);

		static char		_toChar(const std::string& str);
		static bool		_validateChar(const std::string& str);
		
	public:
		static void		convert(const std::string& str);


};

#endif