/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:31:16 by inwagner          #+#    #+#             */
/*   Updated: 2024/10/07 16:11:41 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const char* filename) {
    _readCSVToMap(DATABASE_NAME);
    _readTxtToMap(filename);
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


void BitcoinExchange::_readTxtToMap(const char* filename) {    
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::invalid_argument("Error: could not open file.");

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
                throw std::invalid_argument("Error: could not convert value.");

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