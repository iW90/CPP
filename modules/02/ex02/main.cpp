/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:00:48 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/22 16:28:26 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;

	//std::cout << a / 0 << std::endl; //Gera uma exception
	
	return 0;
}

/*
int main( void ) {
	// Default constructor
	Fixed a;
	std::cout << "a: " << a << std::endl;

	// Constructor with int
	Fixed b(10);
	std::cout << "b (from int): " << b << std::endl;

	// Constructor with float
	Fixed c(42.42f);
	std::cout << "c (from float): " << c << std::endl;

	// Copy constructor
	Fixed d(b);
	std::cout << "d (copy of b): " << d << std::endl;

	// Assignment operator
	a = c;
	std::cout << "a (after assignment from c): " << a << std::endl;

	// getRawBits and setRawBits
	std::cout << "a raw bits: " << a.getRawBits() << std::endl;
	a.setRawBits(123456);
	std::cout << "a (after setRawBits): " << a << " raw bits: " << a.getRawBits() << std::endl;

	// toFloat and toInt
	std::cout << "a to float: " << a.toFloat() << std::endl;
	std::cout << "a to int: " << a.toInt() << std::endl;

	std::cout << "a raw bits: " << a.getRawBits() << std::endl;
	std::cout << "b raw bits: " << b.getRawBits() << std::endl;
	std::cout << "c raw bits: " << c.getRawBits() << std::endl;
	std::cout << "d raw bits: " << d.getRawBits() << std::endl;

	// Comparison operators
	std::cout << "b > c: " << (b > c) << std::endl;
	std::cout << "b < c: " << (b < c) << std::endl;
	std::cout << "b >= d: " << (b >= d) << std::endl;
	std::cout << "b <= d: " << (b <= d) << std::endl;
	std::cout << "b == d: " << (b == d) << std::endl;
	std::cout << "b != c: " << (b != c) << std::endl;

	// Arithmetic operators
	Fixed e = b + c;
	std::cout << "b + c: " << e << std::endl;
	Fixed f = c - b;
	std::cout << "c - b: " << f << std::endl;
	Fixed g = b * c;
	std::cout << "b * c: " << g << std::endl;
	Fixed h = c / b;
	std::cout << "c / b: " << h << std::endl;

	// Increment and decrement operators
	Fixed i;
	std::cout << "i: " << i << std::endl;
	std::cout << "++i: " << ++i << std::endl;
	std::cout << "i: " << i << std::endl;
	std::cout << "i++: " << i++ << std::endl;
	std::cout << "i: " << i << std::endl;
	std::cout << "--i: " << --i << std::endl;
	std::cout << "i: " << i << std::endl;
	std::cout << "i--: " << i-- << std::endl;
	std::cout << "i: " << i << std::endl;

	// Min and max functions
	std::cout << "min(b, c): " << Fixed::min(b, c) << std::endl;
	std::cout << "max(b, c): " << Fixed::max(b, c) << std::endl;

	// Testing the given example
	Fixed const j(Fixed(5.05f) * Fixed(2));
	std::cout << "j: " << j << std::endl;

	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;

	std::cout << "b: " << b << std::endl;
	std::cout << "Fixed::max(a, j): " << Fixed::max(a, j) << std::endl;

	return 0;
}
*/