/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:22:11 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/22 18:25:44 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// BSP (Binary Space Partitioning)

#include "Point.hpp"

Fixed Point::_orientation(Point const p1, Point const p2, Point const p3) {
	return (p1.getX() - p3.getX()) * 
			(p2.getY() - p3.getY()) - 
			(p2.getX() - p3.getX()) * 
			(p1.getY() - p3.getY());
}

bool Point::_collinearity(Point const a, Point const b, Point const point) {
	return _orientation(a, b, point) == 0 && 
			point.getX() >= Fixed::min(a.getX(), b.getX()) &&
			point.getX() <= Fixed::max(a.getX(), b.getX()) &&
			point.getY() >= Fixed::min(a.getY(), b.getY()) &&
			point.getY() <= Fixed::max(a.getY(), b.getY());
}

bool Point::bsp(Point const a, Point const b, Point const c, Point const point) {
	if (_collinearity(a, b, point) ||
		_collinearity(b, c, point) ||
		_collinearity(c, a, point))
		return false;

	Fixed d1 = _orientation(point, a, b);
	Fixed d2 = _orientation(point, b, c);
	Fixed d3 = _orientation(point, c, a);

	bool negativeOrientation = (d1 < 0) || (d2 < 0) || (d3 < 0);
	bool positiveOrientation = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(negativeOrientation && positiveOrientation);
}


/*
	To conclude, implement the following function in the appropriate file:
		bool bsp( Point const a, Point const b, Point const c, Point const point);
		
		• a, b, c: The vertices of our beloved triangle.
		• point: The point to check.
		• Returns: True if the point is inside the triangle. False otherwise.
		
		Thus, if the point is a vertex or on edge, it will return False.
		Implement and turn in your own tests to ensure that your class behaves as expected.
*/