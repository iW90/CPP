/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:37:44 by inwagner          #+#    #+#             */
/*   Updated: 2024/11/15 15:18:46 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
    // Test with an array of integers
    int intArray[] = {0, 1, 2, 3, 4, 42, 42, 42, 42, 42};
    size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);
    iter(intArray, intArrayLength, printer<int>);

    // Test with an array of doubles
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleArrayLength = sizeof(doubleArray) / sizeof(doubleArray[0]);
    iter(doubleArray, doubleArrayLength, printer<double>);

    // Test with an array of chars
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charArrayLength = sizeof(charArray) / sizeof(charArray[0]);
    iter(charArray, charArrayLength, printer<char>);

    return 0;
}