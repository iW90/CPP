/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 11:13:24 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/16 13:58:35 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA {
	private:
		std::string _name;
		Weapon& _weapon;
		HumanA();

	public:
		void attack(void);

		//Constructor/Destructor
		HumanA(std::string name, Weapon& weapon);
		~HumanA();

};

#endif //HUMANA_HPP