/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:25:32 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/09 17:44:08 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include <sstream>
# include <string>
# include <limits>
# include "Contact.hpp"

// It has an array of contacts.
// It can store a maximum of 8 contacts. If the user tries to add a 9th contact, replace the oldest one by the new one.
// Please note that dynamic allocation is forbidden.
class PhoneBook {
	private:
		Contact _phonebook[8];

		static std::string _get_input(const std::string str);
		static void _print_field(const std::string& field);
		static void _print_contact(const Contact& contact, const int& id);
		static void _print_contact_by_id(const Contact& contact);
		static void _display_contacts_list(PhoneBook& phonebook);
		static bool _validate_input(const std::string& input);
		static bool _validate_number(const std::string& number);
		

	public:
		// Default Constructor
		PhoneBook();

		// Constructor
		PhoneBook(const Contact& contact);

		// Copy Constructor
		PhoneBook(const PhoneBook& other);

		// Copy Assignment Operator
		PhoneBook& operator=(const PhoneBook& other);

		// Destructor
		~PhoneBook();

		// Getters and Setters
		Contact get_contact_by_id(int id);
		void set_contact(int index, Contact& contact);

		// Features
		void add_new_contact(void);
		void search_contact_by_id(void);
		void display_contacts(void);
};

#endif //PHONEBOOK_HPP