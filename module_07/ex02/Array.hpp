/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:48:25 by inwagner          #+#    #+#             */
/*   Updated: 2024/10/03 21:11:54 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>


template <typename T>
class Array {
    private:
        T* data;          // Ponteiro para os dados do array
        unsigned int len; // Tamanho do array

    public:
        Array();
        
        ~Array();
        
        Array(const Array& other);
        
        Array& operator=(const Array& other);

        // Construtor com parâmetro de tamanho
        Array(unsigned int n);

        // Operador de subscrição
        T& operator[](int index);

        // Versão const do operador de subscrição
        const T& operator[](int index) const;

        // Função size
        unsigned int size() const;
};

# include "Array.tpp"

#endif