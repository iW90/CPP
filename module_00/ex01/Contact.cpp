/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:31:20 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/09 10:55:19 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Default Constructor
Contact::Contact() 
: first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("") {}

// Constructor
Contact::Contact(const std::string& fname, const std::string& lname, const std::string& nick, const std::string& number, const std::string& secret) 
: first_name(fname), last_name(lname), nickname(nick), phone_number(number), darkest_secret(secret) {}

// Copy Constructor
Contact::Contact(const Contact& other)
: first_name(other.first_name), last_name(other.last_name), 
nickname(other.nickname), phone_number(other.phone_number), darkest_secret(other.darkest_secret) {}

// Copy Assignment Operator
Contact& Contact::operator=(const Contact& other) {
	if (this != &other) {
		first_name = other.first_name;
		last_name = other.last_name;
		nickname = other.nickname;
		phone_number = other.phone_number;
		darkest_secret = other.darkest_secret;
	}
	return *this;
}

// Destructor
Contact::~Contact() {}

// Getters and Setters
std::string Contact::getFirstName() const {
	return first_name;
}

void Contact::setFirstName(const std::string& fname) {
	first_name = fname;
}

std::string Contact::getLastName() const {
	return last_name;
}

void Contact::setLastName(const std::string& lname) {
	last_name = lname;
}

std::string Contact::getNickname() const {
	return nickname;
}

void Contact::setNickname(const std::string& nick) {
	nickname = nick;
}

std::string Contact::getPhoneNumber() const {
	return phone_number;
}

void Contact::setPhoneNumber(const std::string& number) {
	phone_number = number;
}

std::string Contact::getDarkestSecret() const {
	return darkest_secret;
}

void Contact::setDarkestSecret(const std::string& secret) {
	darkest_secret = secret;
}
