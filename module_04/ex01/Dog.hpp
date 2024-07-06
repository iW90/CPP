/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:37:04 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/06 09:41:19 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain* _brain;

	public:
		~Dog();
		Dog();
		Dog(Dog& dog);
		Dog& operator=(Dog& other);

		void makeSound() const;

		void setIdea(const std::string idea, int idx);
		const std::string getIdea(int idx) const;
};

#endif //DOG_HPP