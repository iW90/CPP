/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:14:59 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/17 19:53:25 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_FRAC_BITS = 8;

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;	
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	_fixed_point = value << _FRAC_BITS;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	_fixed_point = roundf(value * (1 << _FRAC_BITS));
}

Fixed::Fixed(const Fixed &other) : _fixed_point(other._fixed_point) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		_fixed_point = other._fixed_point;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _fixed_point;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_fixed_point = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(_fixed_point) / (1 << _FRAC_BITS);
}

int Fixed::toInt(void) const {
	return _fixed_point >> _FRAC_BITS;
}

// Non member function
std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}
