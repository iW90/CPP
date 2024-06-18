/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:07:37 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/18 14:46:36 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef POINT_HPP
# define POINT_HPP

# include <cmath>
# include <iostream>
# include "Fixed.hpp"

class Point {
	private:
		Fixed _x;
		Fixed _y;

	public:
		Point();
		Point(const Fixed& x, const Fixed& y);
		Point(const Point& other);
		~Point();

		Point& operator=(const Point& other);
	
		bool bsp(Point const a, Point const b, Point const c, Point const point);

};

#endif //POINT_HPP


/*
	Let’s start by creating the class Point in Orthodox Canonical Form that represents a 2D point:
	• Private members:
		◦ A Fixed const attribute x.
		◦ A Fixed const attribute y.
		◦ Anything else useful.
	• Public members:
		◦ A default constructor that initializes x and y to 0.
		◦ A constructor that takes as parameters two constant floating-point numbers.
	
	It initializes x and y with those parameters.
		◦ A copy constructor.
		◦ A copy assignment operator overload.
		◦ A destructor.
		◦ Anything else useful.
*/