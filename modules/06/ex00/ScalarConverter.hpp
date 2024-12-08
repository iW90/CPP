/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:30:53 by inwagner          #+#    #+#             */
/*   Updated: 2024/10/01 21:06:00 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <sstream>
# include <stdexcept>
# include <cstdlib>
# include <cerrno>

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
	
	public:
		static void		convert(const std::string& str);
};

#endif