/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:31:07 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/19 19:41:53 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>
# include "WrongCat.hpp"

class WrongAnimal : public WrongCat {
	private:

	public:
		virtual ~WrongAnimal();
		WrongAnimal();
		WrongAnimal(WrongAnimal& Wronganimal);
		WrongAnimal& operator=(WrongAnimal& other);
	
		virtual void makeSound()const;
};

#endif //WRONGANIMAL_HPP