/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 08:43:45 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/23 11:03:20 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	private:


	protected:
		FragTrap();										// empty constructor

	public:
		FragTrap(std::string name);						// default constructor
		FragTrap(FragTrap const &other);				// copy constructor
		FragTrap& operator=(const FragTrap &other);		// copy operator constructor
		virtual ~FragTrap();							// destructor

		void attack(const std::string &target);
		void highFivesGuys(void);
	
};

#endif //FRAGTRAP_HPP