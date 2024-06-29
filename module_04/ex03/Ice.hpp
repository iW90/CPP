/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:05:24 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/29 11:20:52 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "ICharacter.hpp"
# include "IMateriaSource.hpp"

class Ice : public AMateria {
	public:
		~Ice(); 						// Destructor
		Ice(); 							// Default constructor
		Ice(const Ice& other); 			// Copy constructor
		Ice& operator=(const Ice& other); // Copy assignment operator overload

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif //ICE_HPP
