/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:32:28 by inwagner          #+#    #+#             */
/*   Updated: 2024/10/03 19:45:46 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
void    iter(T* array, int len, void (*func)(T)) {
    for (int i = 0; i < len; i++) {
        func(array[i]);
    }
}

template <typename T>
void printer(T element) {
    std::cout << element << std::endl;
}

#endif