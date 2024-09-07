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

void ScalarConverter::convert(const std::string& str) {
    char        convertedChar;
    int         convertedInt;
    float       convertedFloat;
    double      convertedDouble;

    convertedChar = toChar(str);
    std::cout << convertedChar << std::endl;

    convertedInt = toInt(str);
    std::cout << convertedInt << std::endl;

    convertedFloat = toFloat(str);
    std::cout << convertedInt << std::endl;

    convertedDouble = toDouble(str);
    std::cout << convertedDouble << std::endl;
}

char ScalarConverter::toChar(const std::string& str) {
    if (!_isChar(str))
        return 1;
}

int ScalarConverter::toInt(const std::string& str) {
    std::stringstream   ss(str);
    int                 number;

    ss >> number;

    if (ss.fail()) {
        std::cerr << "Falha ao converter para inteiro" << std::endl;
        return 1;
    }

    return number;
}

float ScalarConverter::toFloat(const std::string& str) {

    return 1; 
}

double ScalarConverter::toDouble(const std::string& str) {

    return 1; 
}


// funções auxiliares

bool ScalarConverter::_isChar(const std::string& str) {
    if (str.empty())
        return false;

    

    if (str.length() == 1 && _isPrintableChar(str[0]))
        return true;

}

bool ScalarConverter::_isDigitChar(const std::string& str) {
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isdigit(*it))
            return false;
    }
    return true;
}

bool ScalarConverter::_isPrintableChar(int ch) {
    return (ch >= 0 && ch <= 255) && std::isprint(static_cast<unsigned char>(ch));
}

