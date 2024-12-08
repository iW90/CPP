/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:22:55 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/12 22:21:27 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
	private:
		std::string _name;

	public:
		// Default Constructor
		Zombie();
		
		// Constructor
		Zombie(const std::string& name);

		// Destructor
		~Zombie();

		std::string getName();
		
		void setName(std::string& name);

		void announce( void ); 
	
		Zombie* zombieHorde( int N, std::string name );
};

#endif