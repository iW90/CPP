/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:37:40 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/06 10:53:43 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain* _brain;

	public:
		~Cat();
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);

		void makeSound() const;

		void setIdea(const std::string idea, int idx);
		const std::string getIdea(int idx) const;
};

#endif //CAT_HPP