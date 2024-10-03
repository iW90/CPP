/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:38:11 by inwagner          #+#    #+#             */
/*   Updated: 2024/10/03 19:19:42 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WHATEVER_HPP
# define WHATEVER_HPP


template <typename T>
void swap(T& a, T& b) {
    a = a + b; // Soma
    b = a - b; // b agora contém o valor original de a
    a = a - b; // a agora contém o valor original de b
}

//min
template <typename T>
T&  min(T& a, T& b) {
    return (a < b) ? a : b;
}

//max
template <typename T>
T&  max(T& a, T& b) {
    return (a > b) ? a : b;
}

#endif