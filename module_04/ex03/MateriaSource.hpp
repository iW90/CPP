/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:10:04 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/29 12:01:20 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria*    _memory[4];
		unsigned int _idx;

	public:
		~MateriaSource();                                   	// Destructor
		MateriaSource();                                    	// Default constructor
		MateriaSource(const MateriaSource& other);            	// Copy constructor
		MateriaSource& operator=(const MateriaSource& other); 	// Copy assignment operator overload
		
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
		AMateria* getMateria( unsigned int idx );
		AMateria** getMaterias();
};

#endif
