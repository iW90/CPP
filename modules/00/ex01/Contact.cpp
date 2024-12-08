/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:31:20 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/09 16:25:30 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Default Constructor
Contact::Contact() 
: _first_name(""), _last_name(""), _nickname(""), _phone_number(""), _darkest_secret("") {}

// Constructor
Contact::Contact(const std::string& fname, const std::string& lname, const std::string& nick, const std::string& number, const std::string& secret) 
: _first_name(fname), _last_name(lname), _nickname(nick), _phone_number(number), _darkest_secret(secret) {}

// Copy Constructor
Contact::Contact(const Contact& other)
: _first_name(other._first_name), _last_name(other._last_name), 
_nickname(other._nickname), _phone_number(other._phone_number), _darkest_secret(other._darkest_secret) {}

// Copy Assignment Operator
Contact& Contact::operator=(const Contact& other) {
	if (this != &other) {
		_first_name = other._first_name;
		_last_name = other._last_name;
		_nickname = other._nickname;
		_phone_number = other._phone_number;
		_darkest_secret = other._darkest_secret;
	}
	return *this;
}

// Destructor
Contact::~Contact() {}

// Getters and Setters
std::string Contact::getFirstName() const {
	return _first_name;
}

void Contact::setFirstName(const std::string& fname) {
	_first_name = fname;
}

std::string Contact::getLastName() const {
	return _last_name;
}

void Contact::setLastName(const std::string& lname) {
	_last_name = lname;
}

std::string Contact::getNickname() const {
	return _nickname;
}

void Contact::setNickname(const std::string& nick) {
	_nickname = nick;
}

std::string Contact::getPhoneNumber() const {
	return _phone_number;
}

void Contact::setPhoneNumber(const std::string& number) {
	_phone_number = number;
}

std::string Contact::getDarkestSecret() const {
	return _darkest_secret;
}

void Contact::setDarkestSecret(const std::string& secret) {
	_darkest_secret = secret;
}
