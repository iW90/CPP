/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:05:20 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/06 13:10:02 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "IMateriaSource.hpp"

class Cure : public AMateria {
    public:
        ~Cure();                                // Destructor
        Cure();                                 // Default constructor
        Cure(const Cure& other);                // Copy constructor
        Cure& operator=(const Cure& other);     // Copy assignment operator overload

        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif //CURE_HPP
