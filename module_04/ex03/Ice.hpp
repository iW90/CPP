/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:05:24 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/27 19:20:49 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <iostream>

class Ice : public AMateria {
	public:
		Ice();
		virtual ~Ice();
		Ice(const Ice & other);
		Ice & operator=(const Ice & other);

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif //ICE_HPP
