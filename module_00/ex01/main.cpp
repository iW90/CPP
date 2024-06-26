/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:32:20 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/10 20:27:00 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void) {
	std::string option;
	PhoneBook phonebook;
	
	while (true) {
		std::cout << "Choose an option:" << std::endl;
		std::cout << "\t> ADD" << std::endl;
		std::cout << "\t> SEARCH" << std::endl;
		std::cout << "\t> EXIT" << std::endl;
		std::getline(std::cin, option);

		if (option == "ADD")
			phonebook.add_new_contact();
		else if (option == "SEARCH")
			phonebook.display_contacts();
		else if (option == "EXIT")
			break;
		else
			std::cerr << "Invalid option.\n" << std::endl;	
	}
	return 0;
}

/*
In your code, the phonebook must be instantiated as an instance of the PhoneBook
class. Same thing for the contacts. Each one of them must be instantiated as an instance
of the Contact class. You’re free to design the classes as you like but keep in mind that
anything that will always be used inside a class is private, and that anything that can be
used outside a class is public.

On program start-up, the phonebook is empty and the user is prompted to enter one
of three commands. The program only accepts ADD, SEARCH and EXIT.

Once a command has been correctly executed, the program waits for another one. It
stops when the user inputs EXIT.

• Any other input is discarded.
Give a relevant name to your executable.
*/