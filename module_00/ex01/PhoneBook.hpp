/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:25:32 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/08 18:29:28 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include <sstream>
# include <string>
# include "Contact.hpp"

// It has an array of contacts.
// It can store a maximum of 8 contacts. If the user tries to add a 9th contact, replace the oldest one by the new one.
// Please note that dynamic allocation is forbidden.
class PhoneBook {
    private:
        Contact phonebook[8];

        static void printField(const std::string& field);
        static std::string validate_contact(std::string str);

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
        void set_contact(int index, Contact contact);

        // Features
        void add_new_contact(void);
        void search_contact_by_id(void);
};

#endif