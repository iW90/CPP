/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:05:20 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/19 21:07:24 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {
public:
    Cure();
    virtual ~Cure();
    Cure(const Cure & other);
    Cure & operator=(const Cure & other);

    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif //CURE_HPP
