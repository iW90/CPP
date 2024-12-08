/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:37:36 by inwagner          #+#    #+#             */
/*   Updated: 2024/10/03 19:27:05 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"
#include <iostream>

int main( void ) {
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}

// int main() {
//     double x = 5.5, y = 10;

//     // Testing swap
//     std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
//     swap(x, y);
//     std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

//     // Testing min and max
//     std::cout << "\nMin of x and y: " << min(x, y) << std::endl;
//     std::cout << "Max of x and y: " << max(x, y) << std::endl;

//     // Modifying the value through min and max
//     min(x, y) = 3; // This will set the smaller value (x) to 3
//     std::cout << "\nAfter setting min to 3, x = " << x << ", y = " << y << std::endl;

//     max(x, y) = 15; // This will set the greater value (y) to 15
//     std::cout << "After setting max to 15, x = " << x << ", y = " << y << std::endl;

//     return 0;
// }
