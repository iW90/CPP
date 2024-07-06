/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:34:10 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/06 11:33:28 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal {
	private:


	protected:
		std::string _type;
		AAnimal();

	public:
		virtual ~AAnimal();
		AAnimal(const AAnimal& animal);
		AAnimal& operator=(const AAnimal& other);
		
		std::string getType() const;
		void setType(std::string type);
	
		virtual void makeSound() const = 0;
};

#endif //AANIMAL_HPP