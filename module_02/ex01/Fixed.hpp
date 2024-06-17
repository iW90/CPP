/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:14:56 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/17 19:53:54 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed {
	private:
		int _fixed_point;
		static const int _FRAC_BITS;
	
	public:
		Fixed();							// Construtor padrão
		Fixed(const int value);				// Construtor com int
		Fixed(const float value);			// Construtor com float
		Fixed(const Fixed& other);			// Construtor de cópia
		~Fixed();							// Destrutor
		
		// Copy assignment operator overload
		Fixed& operator=(const Fixed& other);

		// Getters & Setters
		int getRawBits( void ) const;
		void setRawBits( int const raw );

		// Member Functions
		float toFloat( void ) const;
		int toInt( void ) const;

};

// Non-member functions
// An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter.
// This has to be declard as a nonmember function because of the implicit *this* parameter.
std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

/*
	Não é possível declarar a função de sobrecarga de operador << como membro de uma classe 
	porque o operador << precisa ter o ostream como seu primeiro operando, e um membro da 
	classe teria implicitamente a própria instância da classe como o primeiro operando.
*/

#endif //FIXED_HPP