/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:31:16 by inwagner          #+#    #+#             */
/*   Updated: 2024/12/16 20:16:43 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange() {
    _readFile(DATABASE_NAME, ',', &BitcoinExchange::_readDatabase);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other)
		_dataMap = other._dataMap;
    return (*this);
}


void BitcoinExchange::showResults(const char* filename) {
    if (_dataMap.empty())
        throw std::invalid_argument("Error: database is empty.");
    _readFile(filename, '|', &BitcoinExchange::_calculateBitcoin);
}



void BitcoinExchange::_removeSpaces(std::string& str) {
    std::string result;
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] != ' ')
            result += str[i];
    }
    str = result;
}

float   BitcoinExchange::_stringToFloat(const std::string& num) {
    char    remaining;
    float   value;
    long    longValue;

    std::istringstream iss(num);
    if (!(iss >> value) || iss >> remaining) {
        std::cerr << "Error: bad input => " + num << std::endl;
        return -1.0f;
    }
    if (value < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return -1.0f;
    }

    std::istringstream(num) >> longValue;
    if (longValue > std::numeric_limits<int>::max()) {
        std::cerr << "Error: too large a number." << std::endl;
        return -1.0f;
    }

    return value;
}

bool BitcoinExchange::_isValidDate(Date date) {
    if (date.month < 1 || date.month > 12 || date.year < 2009 || date.year > 2024)
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0))
        daysInMonth[1] = 29;

    return date.day >= 1 && date.day <= daysInMonth[date.month - 1];
}

Date BitcoinExchange::_stringToDate(std::string dateStr) {
    Date nullDate = {0, 0, 0};
    Date date;

    if (dateStr.size() != 10 || dateStr[4] != '-' || dateStr[7] != '-') {
        std::cerr << "Error: bad input => " + dateStr << std::endl;
        return nullDate;
    }
    
    date.year = atoi(dateStr.substr(0, 4).c_str());
    date.month = atoi(dateStr.substr(5, 2).c_str());
    date.day = atoi(dateStr.substr(8, 2).c_str());

    if (!_isValidDate(date)) {
        std::cerr << "Error: bad input => " + dateStr << std::endl;
        return nullDate;
    }

    return date;
}


void BitcoinExchange::_readDatabase(Date date, float exc) {
    _dataMap[date] = exc;
}

void BitcoinExchange::_readFile(const char* filename, char delimiter, void (BitcoinExchange::*action)(Date, float)) {    
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::invalid_argument("Error: could not open file.");

    std::string line;
    std::getline(file, line);
    _removeSpaces(line);

    if (line != "date,exchange_rate" && line != "date|value")
        throw std::invalid_argument("Error: invalid header.");

    while (std::getline(file, line)) {
        if (line.length() < 1)
            continue;
        
        if (line.find(delimiter) == std::string::npos) {
            std::cerr << "Error: bad input => " + line << std::endl;
            continue;
        }

        _removeSpaces(line);
        std::stringstream   ss(line);
        std::string         strDate;
        std::string         strExch;
        float               exchange_rate;
        Date                date;


        std::getline(ss, strDate, delimiter) && std::getline(ss, strExch, delimiter);
        if (ss.fail() || strDate.length() < 1 || strExch.length() < 1) {
            std::cerr << "Error: bad input => " + line << std::endl;
            continue;
        }

        
        date = _stringToDate(strDate);
        if (date.day == 0)
            continue;
        
        exchange_rate = _stringToFloat(strExch);

        if (exchange_rate == -1.0f)
            continue;
        
        (this->*action)(date, exchange_rate);
        
    }

    file.close();
}

float BitcoinExchange::_searchValueByDate(Date date) {
    std::map<Date, float>::iterator it = _dataMap.find(date);
    if (it != _dataMap.end())
        return it->second;

        
    float   value;
    bool    foundPrevious = false;

    for (it = _dataMap.begin(); it != _dataMap.end(); ++it) {
        if (it->first < date) {
            value = it->second;
            foundPrevious = true;
        } else
            break;
    }

    if (foundPrevious)
        return value;

    return _dataMap.begin()->second;
}

void BitcoinExchange::_calculateBitcoin(Date date, float exc) {
    if (exc > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return ;
    }
    
    float exchange = _searchValueByDate(date);
    std::cout << std::fixed << std::setprecision(2) << date << " => " << exc << " = ";
    std::cout << exchange * exc  << std::endl;
}


// Non member function
std::ostream& operator<<(std::ostream &out, const Date &date) {
	out << date.toString();
	return out;
}