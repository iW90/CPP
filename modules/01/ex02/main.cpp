/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 10:59:13 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/16 11:10:27 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main (void) {
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;
	
	std::cout << "Adresses:" << std::endl;
	std::cout << "String:   \t" << &str << std::endl;
	std::cout << "StringPTR:\t" << &stringPTR << std::endl;
	std::cout << "StringREF:\t" << &stringREF << std::endl;

	std::cout << "\n" << std::endl;

	std::cout << "Values:" << std::endl;
	std::cout << "String:   \t" << str << std::endl;
	std::cout << "StringPTR:\t" << *stringPTR << std::endl;
	std::cout << "StringREF:\t" << stringREF << std::endl;	
}