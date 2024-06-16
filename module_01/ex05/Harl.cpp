/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:25:04 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/16 18:28:40 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


/*
	• "DEBUG" level: Debug messages contain contextual information. They are mostly
	used for problem diagnosis.
	Example: "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
	
	• "INFO" level: These messages contain extensive information. They are helpful for
	tracing program execution in a production environment.
	Example: "I cannot believe adding extra bacon costs more money. You didn’t put
	enough bacon in my burger! If you did, I wouldn’t be asking for more!"
	
	• "WARNING" level: Warning messages indicate a potential issue in the system.
	However, it can be handled or ignored.
	Example: "I think I deserve to have some extra bacon for free. I’ve been coming for
	years whereas you started working here since last month."
	
	• "ERROR" level: These messages indicate an unrecoverable error has occurred.
	This is usually a critical issue that requires manual intervention.
	Example: "This is unacceptable! I want to speak to the manager now."
*/

void Harl::debug( void ) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level ) {
	typedef void (Harl::*HarlMemFn)();
	
	struct LevelMap {
		std::string level;
		HarlMemFn function;
	};

	LevelMap levelMap[] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}
	};

	int numLevels = sizeof(levelMap) / sizeof(LevelMap);

	for (int i = 0; i < numLevels; ++i) {
		if (levelMap[i].level == level) {
			(this->*(levelMap[i].function))();
			return;
		}
	}
	std::cout << "Probably complaining about insignificant problems" << std::endl;
}
