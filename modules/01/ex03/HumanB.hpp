/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 11:13:19 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/16 13:17:34 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB {
	private:
		std::string _name;
		Weapon* _weapon;
		HumanB();

	public:
		void attack(void);


		//Constructor/Destructor
		HumanB(std::string name);
		~HumanB();

		//Getters/Setters
		std::string getName(void)const;
		void setName(std::string name);
		Weapon& getWeapon(void)const;
		void setWeapon(Weapon& weapon);
		

};

#endif //HUMANB_HPP