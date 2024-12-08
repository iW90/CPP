/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:35:00 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/11 21:31:12 by inwagner         ###   ########.fr       */
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
		// Construtor
		Zombie(const std::string& name);

		// Destrutor
		~Zombie();

		// Get e Set
		std::string getName();
		void setName(std::string& name);

		// Features
		void announce( void ); //<name>: BraiiiiiiinnnzzzZ...

		Zombie* newZombie( std::string name ); //It creates a zombie, name it, and return it so you can use it outside of the function scope.
		
		void randomChump( std::string name ); //It creates a zombie, name it, and the zombie announces itself.
};

#endif //ZOMBIE_HPP