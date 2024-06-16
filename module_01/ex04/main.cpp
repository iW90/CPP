/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:14:41 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/16 17:10:59 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

int main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Invalid parameters." << std::endl;
		return 1;
	}

	return Replacer::replacer(av[1], av[2], av[3]);
}
