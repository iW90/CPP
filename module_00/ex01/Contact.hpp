/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:31:13 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/09 16:21:35 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

// Stands for a phonebook contact.
class Contact {
	private:
		std::string     first_name;
		std::string     last_name;
		std::string     nickname;
		std::string     phone_number;
		std::string     darkest_secret;
		
	public:
		// Default Constructor
		Contact();
		
		// Constructor
		Contact(const std::string& fname, const std::string& lname, const std::string& nick, const std::string& number, const std::string& secret);

		// Copy Constructor
		Contact(const Contact& other);

		// Copy Assignment Operator
		Contact& operator=(const Contact& other);

		// Destructor
		~Contact();

		// Getters and Setters
		std::string getFirstName() const;
		void setFirstName(const std::string& fname);
		std::string getLastName() const;
		void setLastName(const std::string& lname);
		std::string getNickname() const;
		void setNickname(const std::string& nick);
		std::string getPhoneNumber() const;
		void setPhoneNumber(const std::string& number);
		std::string getDarkestSecret() const;
		void setDarkestSecret(const std::string& secret);
};

#endif //CONTACT_HPP