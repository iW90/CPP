/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:34:10 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/19 19:24:42 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal {
	private:


	protected:
		std::string _type;

	public:
		virtual ~Animal();
		Animal();
		Animal(Animal& animal);
		Animal& operator=(Animal& other);
		
		std::string getType()const;
		void setType(std::string type);
	
		virtual void makeSound()const;
};

#endif //ANIMAL_HPP