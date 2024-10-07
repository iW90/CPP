/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:31:11 by inwagner          #+#    #+#             */
/*   Updated: 2024/10/07 20:37:57 by inwagner         ###   ########.fr       */
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

# define DATABASE_NAME "data.csv"

struct Date {
    int   day;
    int   month;
    int   year;
};

class BitcoinExchange {
    private:
        std::map<std::string, float>     _dataMap;
        
        void        _readCSVToMap(const char* database);
        void        _readTxt(const char* filename);
        bool        _valiDate(std::string date);
        bool        _isValidDate(int day, int month, int year);
        std::string _removeSpaces(std::string& str);

    public:
        ~BitcoinExchange();
        BitcoinExchange(const char* filename);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);

        void searchDate(const std::string& date);
};

#endif
