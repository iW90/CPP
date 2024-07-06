/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:30:59 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/06 08:58:24 by inwagner         ###   ########.fr       */
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

		void makeSound() const;
};

#endif //WRONGCAT_HPP