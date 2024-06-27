/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:10:04 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/27 19:50:33 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria* templates[4];

public:
    MateriaSource();
    MateriaSource(MateriaSource const & other);
    MateriaSource& operator=(MateriaSource const & other);
    virtual ~MateriaSource();
    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);
};

#endif