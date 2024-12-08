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

    std::cout << "char: ";
    try {
        convertedChar = toChar(str);
        if (std::isprint(convertedChar))
            std::cout << "'" << convertedChar << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "int: ";
    try {
        convertedInt = toInt(str);
        std::cout << convertedInt << std::endl;
    } catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "float: ";
    try {
        convertedFloat = toFloat(str);
        std::cout << convertedFloat << "f"<< std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "double: ";
    try {
        convertedDouble = toDouble(str);
        std::cout << convertedDouble << std::endl;

    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

int ScalarConverter::toInt(const std::string& str) {
    std::stringstream   ss(str);
    int                 number;

    ss >> number;

    if (ss.fail())
        throw std::invalid_argument("impossible");

    return static_cast<int>(number);
}

char ScalarConverter::toChar(const std::string& str) {
    if (str.empty())
        throw std::invalid_argument("impossible");
    

    try {
        int numCh = toInt(str);
        
        if (numCh >= 0 && numCh <= 255)
            return static_cast<char>(numCh);

    } catch (std::exception& e) {
        if (str.length() == 1)
            return static_cast<char>(str[0]);
    }

    throw std::invalid_argument("impossible");
}

double ScalarConverter::toDouble(const std::string& str) {
    errno = 0;
    const char* numCh = str.c_str();
    char* endptr;
    double numDoub = std::strtod(numCh, &endptr);

    if (numCh == endptr || errno == ERANGE)
        throw std::invalid_argument("impossible");

    return static_cast<double>(numDoub);
}


float ScalarConverter::toFloat(const std::string& str) {
    errno = 0;
    const char* numCh = str.c_str();
    char* endptr;
    double numFl = std::strtof(numCh, &endptr);

    if (numCh == endptr || errno == ERANGE)
        throw std::invalid_argument("impossible");

    return static_cast<float>(numFl);
}

// Orthodox Canonical Form
ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){
    (void)other;
	return *this;
}