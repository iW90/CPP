/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:08:33 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/05 18:47:05 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter {
	private:
		std::string _name;
		AMateria*   _inventory[4];
		int         _idx;
		Character();                                	// Default constructor

	public:
		~Character();                               	// Destructor
		Character(std::string const & name);        	// Parameterized constructor
		Character(const Character& other);            	// Copy constructor
		Character& operator=(const Character& other); 	// Copy assignment operator overload

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
