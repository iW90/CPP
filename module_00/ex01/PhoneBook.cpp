/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:25:40 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/10 20:59:22 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// Default Constructor
PhoneBook::PhoneBook() {}

// Constructor
PhoneBook::PhoneBook(const Contact& contact) {
	_phonebook[0] = contact;
}

// Copy Constructor
PhoneBook::PhoneBook(const PhoneBook& other) {
	for (int i = 0; i < 8; ++i) {
		_phonebook[i] = other._phonebook[i];
	}
}

// Copy Assignment Operator
PhoneBook& PhoneBook::operator=(const PhoneBook& other) {
	if (this != &other) {
		for (int i = 0; i < 8; ++i) {
			_phonebook[i] = other._phonebook[i];
		}
	}
	return *this;
}

// Destructor
PhoneBook::~PhoneBook() {}

// Getters and Setters
Contact PhoneBook::get_contact_by_id(int id) {
	if (id >= 0 && id < 8)
		return _phonebook[id];
	else
		return Contact();
}

void PhoneBook::set_contact(int index, Contact& contact) {
	if (index >= 0 && index < 8)
		_phonebook[index] = contact;	
}

// Features
/*
	• ADD: save a new contact
		◦ If the user enters this command, they are prompted to input the information
		of the new contact one field at a time. Once all the fields have been completed,
		add the contact to the phonebook.
		◦ The contact fields are: first name, last name, nickname, phone number, and
		darkest secret. A saved contact can’t have empty fields.
*/
bool PhoneBook::_validate_input(const std::string& input) {
	for (size_t i = 0; i < input.length(); ++i) {
		if (!isspace(input[i])) {
			return true;
		}
	}

	std::cerr << "Invalid input." << std::endl;
	return false;
}

std::string PhoneBook::_get_input(const std::string str) {
	bool isValid = false;
	std::string input;
	
	do {
		std::cout << str << std::flush;
		std::getline(std::cin, input);
		
		isValid = _validate_input(input);
			
	} while (!isValid);

	return input;
}

bool PhoneBook::_validate_number(const std::string& number) {
	for (size_t i = 0; i < number.size(); ++i) {
		if (!isdigit(number[i])) {
			std::cerr << "The phone number must have only digits." << std::endl;
			return false;
		}
	}

	return true;
}

void PhoneBook::add_new_contact(void) {
	std::string fname = _get_input("First name: ");
	std::string lname = _get_input("Last name: ");
	std::string nick = _get_input("Nickname: ");
	std::string number;
	while (true) {
		number = _get_input("Phone number (only digits): ");
		if (_validate_number(number))
			break;
	}
	std::string secret = _get_input("Darkest secret: ");
	std::cout << std::endl;
	
	Contact contact(fname, lname, nick, number, secret);
			
	int index = -1;
	static int oldest = 0;
	
	for (int i = 0; i < 8; ++i) {
		if (_phonebook[i].getFirstName().empty()) {
			index = i;
			break;
		}
	}
	if (index < 0)
		index = (oldest++ % 8);

	set_contact(index, contact);
}

/*
	• SEARCH: display a specific contact
		◦ Display the saved contacts as a list of 4 columns: index, first name, last
		name and nickname.
		◦ Each column must be 10 characters wide. A pipe character (’|’) separates
		them. The text must be right-aligned. If the text is longer than the column,
		it must be truncated and the last displayable character must be replaced by a
		dot (’.’).
		◦ Then, prompt the user again for the index of the entry to display. If the index
		is out of range or wrong, define a relevant behavior. Otherwise, display the
		contact information, one field per line.
*/

void PhoneBook::display_contacts(void) {
	if (_phonebook[0].getFirstName().empty()) {
		std::cout << "Phonebook is empty.\n" << std::endl;
		return ;
	}
	_display_contacts_list(*this);
	search_contact_by_id();	
}

void PhoneBook::_display_contacts_list(PhoneBook& phonebook) {
	std::cout << "---------------------------------------------" << std::endl;
	_print_field("Index");
	_print_field("FirstName");
	_print_field("LastName");
	_print_field("NickName");
	std::cout << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < 8; ++i) {
		Contact contact = phonebook.get_contact_by_id(i);
		if (contact.getFirstName().empty())
			break ;
		_print_contact(contact, i + 1);
	}
	std::cout << "---------------------------------------------\n" << std::endl;
}

void PhoneBook::_print_field(const std::string& field) {
	std::cout << "|";
	if (field.length() > 10) {
		std::cout.width(10);
		std::cout << std::right << field.substr(0, 9) + "." << std::flush;
	} else {
		std::cout.width(10);
		std::cout << std::right << field << std::flush;
	}
}

void PhoneBook::_print_contact(const Contact& contact, const int& id) {
	std::cout << std::right << "|";
	std::cout.width(10);
	std::cout << std::right << id << std::flush;
	_print_field(contact.getFirstName());
	_print_field(contact.getLastName());
	_print_field(contact.getNickname());
	std::cout << "|" << std::endl;
}

void PhoneBook::search_contact_by_id(void) {
	std::string input;

	std::cout << "Choose an index: " << std::flush;
	while (true) {
		std::getline(std::cin, input);
		if (input.length() != 1 || input[0] < '1' || input[0] > '8')
			std::cerr << "The index must be a number between 1 and 8." << std::endl;
		else
			break;
	}
	
	Contact contact = get_contact_by_id(input[0] - '1');

	if (contact.getFirstName().empty())
	{
		std::cerr << "Slot empty.\n" << std::endl;
		return ;
	}

	_print_contact_by_id(contact);
}

void PhoneBook::_print_contact_by_id(const Contact& contact) {
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "First Name:\t" << contact.getFirstName() << std::endl;
	std::cout << "Last Name:\t" << contact.getLastName() << std::endl;
	std::cout << "Nickname:\t" << contact.getNickname() << std::endl;
	std::cout << "Phone Number:\t" << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret:\t" << contact.getDarkestSecret() << std::endl;
	std::cout << "--------------------------------------------------------\n" << std::endl;
}
