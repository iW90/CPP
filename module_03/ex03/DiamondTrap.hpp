/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:03:31 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/19 12:29:52 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
# include <climits>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ClapTrap, public FragTrap, public ScavTrap {
	private:
		std::string _name;


	protected:
		DiamondTrap();											// empty constructor

	public:
		~DiamondTrap();											// destructor
		DiamondTrap(std::string name);							// default constructor
		DiamondTrap(DiamondTrap const &other);					// copy constructor
		DiamondTrap& operator=(const DiamondTrap &other);		// copy operator constructor

		std::string getName()const;
		void setName(std::string& name);
		
		void attack(const std::string &target);
		void whoAmI();

};

#endif //DIAMONDTRAP_HPP