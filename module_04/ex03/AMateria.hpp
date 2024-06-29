/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:45:29 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/29 11:13:19 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria {
	protected:
		std::string _type;
		AMateria();										// Default constructor
		
	public:
		virtual ~AMateria();							// Destructor
		AMateria(std::string const& type);				// Parameterized constructor
		AMateria(const AMateria& other);				// Copy constructor
		AMateria & operator=(const AMateria & other);	// Copy assignment operator overload
		
		std::string const& getType() const; 			// Returns the materia type
		
		virtual AMateria* clone() const = 0;			// Método virtual puro para clonar
		virtual void use(ICharacter& target); 			// Método virtual para usar a materia
};

#endif //AMATERIA_HPP
