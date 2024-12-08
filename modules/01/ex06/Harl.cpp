/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:44:39 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/16 18:28:16 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void ) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.";
	std::cout << "I really do!";
	std:: cout << "\n" << std::endl;
}

void Harl::info( void ) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!";
	std:: cout << "\n" << std::endl;
}

void Harl::warning( void ) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << "I've been coming for years whereas you started working here since last month.";
	std:: cout << "\n" << std::endl;
}

void Harl::error( void ) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std:: cout << "\n" << std::endl;
}

void Harl::complain( std::string level ) {

	LogLevel log = getLogLevel(level);

	switch (log) {
        case DEBUG:
            this->debug();
			// fall through
        case INFO:
            this->info();
			// fall through
        case WARNING:
            this->warning();
			// fall through
        case ERROR:
            this->error();
			break;
		default:
			std::cout << "Probably complaining about insignificant problems" << std::endl;
	}
}

LogLevel Harl::getLogLevel(const std::string& level) {
    if (level == "DEBUG") return DEBUG;
    if (level == "INFO") return INFO;
    if (level == "WARNING") return WARNING;
    if (level == "ERROR") return ERROR;
    return static_cast<LogLevel>(-1);
}