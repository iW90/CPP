/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:30:53 by inwagner          #+#    #+#             */
/*   Updated: 2024/09/07 15:02:17 by inwagner         ###   ########.fr       */
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

		static char		toChar(const std::string& str);
		static int		toInt(const std::string& str);
		static float	toFloat(const std::string& str);
		static double	toDouble(const std::string& str);

		
		static bool		_validateChar(const std::string& str);
		
	public:
		static void		convert(const std::string& str);


};

#endif