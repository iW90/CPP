/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:00:40 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/18 12:42:56 by inwagner         ###   ########.fr       */
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

		// Getters & Setters
		int getRawBits( void ) const;
		void setRawBits( int const raw );

		// Member Functions
		float toFloat( void ) const;
		int toInt( void ) const;

		static Fixed& min(Fixed& n1, Fixed& n2);
		static Fixed& max(Fixed& n1, Fixed& n2);
		static const Fixed& min(const Fixed& n1, const Fixed& n2);
		static const Fixed& max(const Fixed& n1, const Fixed& n2);
		
		// Operators
		Fixed& operator=(const Fixed& other);	// Copy assignment operator overload
		
		bool operator>(const Fixed& other)const;	// Comparison operator overload
		bool operator<(const Fixed& other)const;	// Comparison operator overload
		bool operator>=(const Fixed& other)const;	// Comparison operator overload
		bool operator<=(const Fixed& other)const;	// Comparison operator overload
		bool operator==(const Fixed& other)const;	// Comparison operator overload
		bool operator!=(const Fixed& other)const;	// Comparison operator overload
		
		Fixed operator+(const Fixed& other);	// Arithmetic operator overload
		Fixed operator-(const Fixed& other);	// Arithmetic operator overload
		Fixed operator*(const Fixed& other);	// Arithmetic operator overload
		Fixed operator/(const Fixed& other);	// Arithmetic operator overload
		
		Fixed& operator++(void);				// Pre-increment operator overload
		Fixed& operator--(void);				// Pre-decrement operator overload
		Fixed operator++(int);					// Pos-increment operator overload
		Fixed operator--(int);					// Pos-decrement operator overload
};

// Non-member functions
std::ostream& operator<<(std::ostream &out, const Fixed &fixed);


#endif //FIXED_HPP


/*
	Add public member functions to your class to overload the following operators:
		• The 6 comparison operators: >, <, >=, <=, == and !=.
		• The 4 arithmetic operators: +, -, *, and /.
		• The 4 increment/decrement (pre-increment and post-increment, pre-decrement and
			post-decrement) operators, that will increase or decrease the fixed-point value from
			the smallest representable ϵ such as 1 + ϵ > 1.

	Add these four public overloaded member functions to your class:
		• A static member function min that takes as parameters two references on fixed-point
			numbers, and returns a reference to the smallest one.
		• A static member function min that takes as parameters two references to constant
			fixed-point numbers, and returns a reference to the smallest one.
		• A static member function max that takes as parameters two references on fixed-point
			numbers, and returns a reference to the greatest one.
		• A static member function max that takes as parameters two references to constant
			fixed-point numbers, and returns a reference to the greatest one.
*/