/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:31:16 by inwagner          #+#    #+#             */
/*   Updated: 2024/10/07 20:42:40 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const char* filename) {
    _readCSVToMap(DATABASE_NAME);
    (void)filename;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other)
		*this = other;
    return (*this);
}



void BitcoinExchange::_readCSVToMap(const char* database) {    
    std::ifstream file(database);
    if (!file.is_open())
        throw std::invalid_argument("Erro ao abrir o arquivo: ");

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        std::string exchStr;
        float exchange_rate;

        if (std::getline(ss, date, ',') && std::getline(ss, exchStr, ',')) {

            std::istringstream(exchStr) >> exchange_rate;
            if (ss.fail() || !ss.eof())
                throw std::invalid_argument("Erro ao converter o valor");

            _dataMap[date] = exchange_rate;
        }
    }

    file.close();
}


void BitcoinExchange::_readTxt(const char* filename) {    
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::invalid_argument("Error: could not open file.");

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream ss(_removeSpaces(line));
        std::string date;
        std::string exchStr;
        float exchange_rate;

        if (std::getline(ss, date, '|') && std::getline(ss, exchStr, '|')) {

            std::istringstream(exchStr) >> exchange_rate;
            if (ss.fail() || !ss.eof() || !_txtValidations(date, exchange_rate))
                throw std::invalid_argument("Error: could not convert value.");

            //logica de busca na database

            _dataMap[date] = exchange_rate;
        }
    }

    file.close();
}



void BitcoinExchange::searchDate(const std::string& date) {
    std::map<std::string, float>::iterator it = _dataMap.find(date);

    if (it != _dataMap.end()) {
        std::cout << "Data: " << it->first << ", Valor: " << it->second << std::endl;
    } else {
        std::cout << "Data " << date << " não encontrada." << std::endl;
    }
}

std::string BitcoinExchange::_removeSpaces(std::string& str) {
    std::string result;
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] != ' ')
            result += str[i];
    }
    return result;
}

bool    BitcoinExchange::_txtValidations(std::string date, std::string exc) {
    if (exchange_rate < 0)
        throw std::invalid_argument("Error: not a positive number.");
    if (exchange_rate >= INT_MAX)
        throw std::invalid_argument("Error: too large a number.");
    if (!_valiDate)
        throw std::invalid_argument("Error: bad input => " + std::string date);
}

bool    BitcoinExchange::_valiDate(std::string dt, Date& date) {
    
    
    return true;
}


bool _isValidDate(int day, int month, int year) {
    if (month < 1 || month > 12 || year < 2009 || year > 2024)
        return false;

    const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)
        daysInMonth[1] == 29;

    return day >= 1 && day <= daysInMonth[month - 1];
}


