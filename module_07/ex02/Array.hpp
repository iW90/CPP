/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:48:25 by inwagner          #+#    #+#             */
/*   Updated: 2024/11/15 16:53:23 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>
# include <cstdlib>
# include <ctime>
# include <iostream>

template <typename T>
class Array {
    private:
        T* data;          // Ponteiro para os dados do array
        unsigned int len; // Tamanho do array

    public:
        Array();
        ~Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        const T& operator[](int index) const;
        T& operator[](int index);

        unsigned int size() const;
};

# include "Array.tpp"

#endif