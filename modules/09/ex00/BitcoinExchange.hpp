/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:31:11 by inwagner          #+#    #+#             */
/*   Updated: 2024/10/11 20:31:06 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <map>
# include <string>
# include <fstream>
# include <stdexcept>
# include <sstream>
# include <iostream>
# include <limits>
# include <cstdlib>
# include <iomanip>


# define DATABASE_NAME "data.csv"

struct Date {
    int   day;
    int   month;
    int   year;

    bool operator<(const Date& other) const {
        if (year != other.year)
            return year < other.year;
        if (month != other.month)
            return month < other.month;
        return day < other.day;
    }

    std::string toString() const {
        std::ostringstream oss;
        oss << std::setw(2) << std::setfill('0') << day << '-'
            << std::setw(2) << std::setfill('0') << month << '-'
            << std::setw(4) << year;
        return oss.str();
    }
};

class BitcoinExchange {
    private:
        std::map<Date, float>     _dataMap;

        bool        _isValidDate(Date date);
        float       _stringToFloat(const std::string& num);
        Date        _stringToDate(std::string dateStr);
        void        _removeSpaces(std::string& str);

        void        _readDatabase(Date date, float exc);
        void        _readFile(const char* filename, char delimiter, void (BitcoinExchange::*action)(Date, float));
        float       _searchValueByDate(Date date);
        void        _calculateBitcoin(Date date, float exc);

    public:
        ~BitcoinExchange();
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);

        void showResults(const char* filename);
};

std::ostream& operator<<(std::ostream &out, const Date &date);
    
#endif
