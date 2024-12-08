/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:00:32 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/22 18:47:55 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_FRAC_BITS = 8;

Fixed::Fixed() : _fixed_point(0) {}

Fixed::Fixed(const int value) {
	_fixed_point = value << _FRAC_BITS;
}

Fixed::Fixed(const float value) {
	_fixed_point = roundf(value * (1 << _FRAC_BITS));
}

Fixed::Fixed(const Fixed& other) : _fixed_point(other._fixed_point) {}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		_fixed_point = other._fixed_point;
	return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const {
	return _fixed_point;
}

void Fixed::setRawBits(int const raw) {
	_fixed_point = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(_fixed_point) / (1 << _FRAC_BITS);
}

int Fixed::toInt(void) const {
	return _fixed_point >> _FRAC_BITS;
}

Fixed& Fixed::min(Fixed& n1, Fixed& n2) {
    return (n1 < n2 ? n1 : n2);
}

Fixed& Fixed::max(Fixed& n1, Fixed& n2) {
	return (n1 > n2 ? n1 : n2);
}

const Fixed& Fixed::min(const Fixed& n1, const Fixed& n2) {
	return (n1 < n2 ? n1 : n2);
}

const Fixed& Fixed::max(const Fixed& n1, const Fixed& n2) {
	return (n1 > n2 ? n1 : n2);
}

bool Fixed::operator>(const Fixed& other)const {
	return this->_fixed_point > other._fixed_point;
}

bool Fixed::operator<(const Fixed& other)const {
	return this->_fixed_point < other._fixed_point;
}

bool Fixed::operator>=(const Fixed& other)const {
	return this->_fixed_point >= other._fixed_point;
}

bool Fixed::operator<=(const Fixed& other)const {
	return this->_fixed_point <= other._fixed_point;
}

bool Fixed::operator==(const Fixed& other)const {
	return this->_fixed_point == other._fixed_point;
}

bool Fixed::operator!=(const Fixed& other)const {
	return this->_fixed_point != other._fixed_point;
}

Fixed Fixed::operator+(const Fixed& other) {
    Fixed result;
    result._fixed_point = this->_fixed_point + other._fixed_point;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) {
    Fixed result;
    result._fixed_point = this->_fixed_point - other._fixed_point;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) {
    Fixed result;
    result._fixed_point = (this->_fixed_point * other._fixed_point) >> _FRAC_BITS;
    return result;
}

Fixed Fixed::operator/(const Fixed& other) {
    Fixed result;
    result._fixed_point = (this->_fixed_point << _FRAC_BITS) / other._fixed_point;
    return result;
}

Fixed& Fixed::operator++(void) {
	this->_fixed_point++;
	return *this;
}

Fixed& Fixed::operator--(void) {
	this->_fixed_point--;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	++(*this);
	return tmp;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    --(*this);
    return tmp;
}

// Non member functions
std::ostream& operator<<(std::ostream &out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}
