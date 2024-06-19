/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:30:59 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/19 19:44:26 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "Animal.hpp"

class WrongCat {
	private:

	protected:
		std::string _type;

	public:
		virtual ~WrongCat();
		WrongCat();
		WrongCat(WrongCat& other);
		WrongCat& operator=(WrongCat& other);

		std::string getType()const;
		void setType(std::string type);

		virtual void makeSound()const;
};

#endif //WRONGCAT_HPP