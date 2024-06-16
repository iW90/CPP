/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:44:36 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/16 18:25:52 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

enum LogLevel {
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

class Harl {
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

		LogLevel getLogLevel(const std::string& level);

	public:
		void complain( std::string level );	
	
		
};

#endif //HARL_HPP