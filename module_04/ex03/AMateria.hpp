/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:45:29 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/19 21:04:45 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;
		
	public:
		AMateria(std::string const& type);
		virtual ~AMateria();
		AMateria(const AMateria& other);
		AMateria & operator=(const AMateria & other);
		
		std::string const& getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0; // Método virtual puro para clonar
		virtual void use(ICharacter& target); // Método virtual para usar a materia
};

#endif //AMATERIA_HPP