/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:24:14 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/20 14:44:33 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void megaphone(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i) {
		std::string str(argv[i]);
		for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
			std::cout << static_cast<char>(toupper(*it));
		}
		if (i < argc - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		megaphone(argc, argv);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
