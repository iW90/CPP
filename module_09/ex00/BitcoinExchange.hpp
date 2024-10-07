/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:31:11 by inwagner          #+#    #+#             */
/*   Updated: 2024/10/07 16:16:31 by inwagner         ###   ########.fr       */
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

# define DATABASE_NAME "data.csv"

class BitcoinExchange {
    private:
        std::map<std::string, float>     _dataMap;
        
        void    _readCSVToMap(const char* database);
        void    _readTxtToMap(const char* filename);

    public:
        ~BitcoinExchange();
        BitcoinExchange(const char* filename);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);

        void searchDate(const std::string& date);
};

#endif