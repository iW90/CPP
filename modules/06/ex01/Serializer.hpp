/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:39:12 by inwagner          #+#    #+#             */
/*   Updated: 2024/10/02 19:00:51 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

struct Data {
  std::string   product;
  float         price;
  int           quantity;
};

class Serializer {
	private:
		Serializer();
        ~Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
	
	public:
		static uintptr_t    serialize(Data* ptr);
        //It takes a pointer and converts it to the unsigned integer type uintptr_t.

        static Data*        deserialize(uintptr_t raw);
        //It takes an unsigned integer parameter and converts it to a pointer to Data.
};

#endif