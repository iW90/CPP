/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:18:05 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/19 20:33:53 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain {
	private:

	protected:
		std::string _ideas[100];

	public:
		~Brain();
		Brain();
		Brain(Brain& Brain);
		Brain& operator=(Brain& other);
	
};

#endif //BRAIN_HPP