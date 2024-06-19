/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:23:59 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/19 09:41:17 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	private:
		bool _guardMode;
		
	protected:
		ScavTrap();										// empty constructor

	public:
		ScavTrap(std::string name);						// default constructor
		ScavTrap(ScavTrap const &other);				// copy constructor
		ScavTrap& operator=(const ScavTrap &other);		// copy operator constructor
		~ScavTrap();									// destructor

		bool isGuardMode()const;
		void setGuardMode(bool mode);

		void attack(const std::string &target);
		void guardGate();
};

#endif //SCAVTRAP_HPP