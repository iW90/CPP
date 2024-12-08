/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:41:41 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/16 19:07:51 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int _fixed_point;
		static const int _FRAC_BITS; //always 8


	public:
	// Default Constructor
	Fixed();

	// Copy Constructor
	Fixed(const Fixed& other);
	
	// Copy assignment operator overload
	Fixed& operator=(const Fixed& other);

	// Destructor
	~Fixed();

	// Getters & Setters
	int getRawBits( void ) const;
	void setRawBits( int const raw );


};

#endif // FIXED_HPP