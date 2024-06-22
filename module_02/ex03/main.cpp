/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:22:33 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/22 18:31:38 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void) {
	Point a(0.0f, 0.0f);
	Point b(5.0f, 0.0f);
	Point c(2.5f, 5.0f);

	Point pInside(2.5f, 2.0f);
	Point pOutside(5.0f, 5.0f);
	Point pEdge(2.5f, 0.0f);
	Point pVertex(0.0f, 0.0f);

	bool result1 = Point::bsp(a, b, c, pInside);
	bool result2 = Point::bsp(a, b, c, pOutside);
	bool result3 = Point::bsp(a, b, c, pEdge);
	bool result4 = Point::bsp(a, b, c, pVertex);

	std::cout << "Point pInside is " << (result1 ? "inside" : "outside")
			  << " the triangle." << std::endl;
	std::cout << "Point pOutside is " << (result2 ? "inside" : "outside")
			  << " the triangle." << std::endl;
	std::cout << "Point pEdge is " << (result3 ? "inside" : "outside")
			  << " the triangle." << std::endl;
	std::cout << "Point pVertex is " << (result4 ? "inside" : "outside")
			  << " the triangle." << std::endl;

	return 0;
}