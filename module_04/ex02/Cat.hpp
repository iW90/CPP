/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:37:40 by inwagner          #+#    #+#             */
/*   Updated: 2024/07/06 11:35:05 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {
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