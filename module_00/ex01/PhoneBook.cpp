/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:25:40 by inwagner          #+#    #+#             */
/*   Updated: 2024/06/09 16:17:36 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// Default Constructor
PhoneBook::PhoneBook() {}

// Constructor
PhoneBook::PhoneBook(const Contact& contact) {
	phonebook[0] = contact;
}

// Copy Constructor
PhoneBook::PhoneBook(const PhoneBook& other) {
	for (int i = 0; i < 8; ++i) {
		phonebook[i] = other.phonebook[i];
	}
}

// Copy Assignment Operator
PhoneBook& PhoneBook::operator=(const PhoneBook& other) {
	if (this != &other) {
		for (int i = 0; i < 8; ++i) {
			phonebook[i] = other.phonebook[i];
		}
	}
	return *this;
}

// Destructor
PhoneBook::~PhoneBook() {}

// Getters and Setters
Contact PhoneBook::get_contact_by_id(int id) {
	if (id >= 0 && id < 8)
		return phonebook[id];
	else
		return Contact();
}

void PhoneBook::set_contact(int index, Contact& contact) {
	if (index >= 0 && index < 8)
		phonebook[index] = contact;	
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
bool PhoneBook::validate_input(const std::string& input) {
	for (size_t i = 0; i < input.length(); ++i) {
		if (!isspace(input[i])) {
			return true;
		}
	}

	std::cerr << "Invalid input." << std::endl;
	return false;
}

std::string PhoneBook::get_input(const std::string str) {
	bool isValid = false;
	std::string input;
	
	do {
		std::cout << str << std::flush;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, input);
		
		isValid = validate_input(input);
			
	} while (!isValid);

	return input;
}

bool PhoneBook::validate_number(const std::string& number) {
	for (size_t i = 0; i < number.size(); ++i) {
        if (!isdigit(number[i])) {
			std::cerr << "The phone number must have only digits." << std::endl;
            return false;
		}
    }

	return true;
}

void PhoneBook::add_new_contact(void) {
	std::string fname = get_input("First name: ");
	std::string lname = get_input("Last name: ");
	std::string nick = get_input("Nickname: ");
	std::string number;
	while (true) {
		number = get_input("Phone number (only digits): ");
		if (validate_number(number))
			break;
	}
	std::string secret = get_input("Darkest secret: ");
	
	Contact contact(fname, lname, nick, number, secret);
			
	int index = -1;
	static int oldest = 0;
	
	for (int i = 0; i < 8; ++i) {
		if (phonebook[i].getFirstName().empty()) {
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
void PhoneBook::print_field(const std::string& field) {
	std::cout << "|";
	if (field.length() > 10) {
		std::cout.width(10);
		std::cout << std::right << field.substr(0, 9) + "." << std::flush;
	} else {
		std::cout.width(10);
		std::cout << std::right << field << std::flush;
	}
}

void PhoneBook::print_search(const Contact& contact, const int& id) {
	std::cout << "---------------------------------------------" << std::endl;
	print_field("Index");
	print_field("FirstName");
	print_field("LastName");
	print_field("NickName");
	std::cout << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << std::right << "|";
	std::cout.width(10);
	std::cout << std::right << id << std::flush;
	print_field(contact.getFirstName());
	print_field(contact.getLastName());
	print_field(contact.getNickname());
	std::cout << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

void PhoneBook::search_contact_by_id(void) {
	int id;

	while (true) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> id;
		if (std::cin.fail() || id < 0 || id >= 8)
			std::cerr << "The index must be a number between 0 and 7." << std::endl;
		else {
			break;
		}
	}
	
	Contact contact = get_contact_by_id(id);

	if (contact.getFirstName().empty())
	{
		std::cerr << "Slot empty.\n" << std::endl;
		return ;
	}

	print_search(contact, id);	
}
