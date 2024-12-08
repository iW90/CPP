/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:38:11 by inwagner          #+#    #+#             */
/*   Updated: 2024/10/03 19:30:20 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WHATEVER_HPP
# define WHATEVER_HPP


template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
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