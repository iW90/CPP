/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:48:44 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/19 07:26:33 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>
# include <climits>

class ClapTrap {
	private:
		std::string _name;
		int _hitpoints;
		int _energypoints;
		int _attackdamage;

	protected:
		ClapTrap();

	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		~ClapTrap();

		ClapTrap& operator=(const ClapTrap& other);

		std::string getName()const;
		void setName(std::string& name);
		int getHP()const;
		void setHP(const int hp);
		int getEP()const;
		void setEP(const int ep);
		int getDamage()const;
		void setDamage(const int damage);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	
};

#endif //CLAPTRAP_HPP