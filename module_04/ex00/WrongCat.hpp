/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:30:59 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/29 17:12:17 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	private:

	protected:

	public:
		virtual ~WrongCat();
		WrongCat();
		WrongCat(WrongCat& other);
		WrongCat& operator=(WrongCat& other);

		void makeSound()const;
};

#endif //WRONGCAT_HPP