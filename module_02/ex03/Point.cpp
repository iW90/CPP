/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:22:22 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/22 18:27:58 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const Fixed& x, const Fixed& y) : _x(x), _y(y) {}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

Point& Point::operator=(const Point& other) {
    if (this != &other) {
        _x = other._x;
        _y = other._y;
    }
    return *this;
}

Point::~Point() {}

Fixed Point::getX() const {
  return _x;
}

Fixed Point::getY() const {
  return _y;
}
