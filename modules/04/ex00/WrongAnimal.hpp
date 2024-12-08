/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:31:07 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/06 08:58:12 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal {
	private:

	protected:
		std::string _type;

	public:
		virtual ~WrongAnimal();
		WrongAnimal();
		WrongAnimal(WrongAnimal& Wronganimal);
		WrongAnimal& operator=(WrongAnimal& other);

		std::string getType() const;
		void setType(std::string type);
	
		void makeSound() const;
};

#endif //WRONGANIMAL_HPP