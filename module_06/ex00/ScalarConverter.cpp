#include "ScalarConverter.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_types.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:30:42 by inwagner          #+#    #+#             */
/*   Updated: 2024/09/06 19:30:43 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>

int stringToInt(const std::string& str) {
    return std::atoi(str.c_str());
}


void ScalarConverter::convert(const std::string& str) {
    char        convertedChar;
    //int         convertedInt;
    //float       convertedFloat;
    //double      convertedDouble;

    convertedChar = _toChar(str);
    std::cout << convertedChar << std::endl;
}

char ScalarConverter::_toChar(const std::string& str) {
    if (!_validateChar(str))
        return 1;
    

}

bool ScalarConverter::_validateChar(const std::string& str) {
    if (str.empty()) return false;

    

    if (str.length() > 1)
        return false;

    

}

bool isDigitChar(const std::string& str) {
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isdigit(*it)) {
            return false;
        }
    }
    return true;
}

bool isPrintableChar(int ch) {
    return (ch >= 0 && ch <= 255) && std::isprint(static_cast<unsigned char>(ch));
}

int toInt(const std::string& str) {
    std::stringstream   ss(str);
    int                 number;

    ss >> number;
    return number;
}

