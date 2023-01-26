#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "PhoneBook.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

// Utils

bool is_onlydigits(string input)
{
	for (size_t i = 0; i < input.length(); i += 1)
		if (!isdigit(input[i]))
			return false;
	return true;
}

string get_formatted_field(const string field)
{
	if (field.length() > 10)
		return field.substr(0,9) + ".";
	return field;
}

void display_contact_info(Contact contact)
{
	cout << endl;
	cout << "First name: " << contact.getFirstName() << endl;
	cout << "Last name: " << contact.getLastName() << endl;
	cout << "Nickname: " << contact.getNickname() << endl;
	cout << "Phone number: " << contact.getPhoneNumber() << endl;
	cout << "Darkest secret: " << contact.getDarkestSecret() << endl;
	cout << endl;
}

// Default constructor
PhoneBook::PhoneBook() : count(0) {}

void PhoneBook::addContact(void)
{
	Contact	new_contact;
	string	input;

	cout << "First name: ";
	getline(cin, input);
	new_contact.setFirstName(input);

	cout << "Last name: ";
	getline(cin, input);
	new_contact.setLastName(input);

	cout << "Nickname: ";
	getline(cin, input);
	new_contact.setNickName(input);

	while (1)
	{
		cout << "Phone number 📞: ";
		getline(cin, input);
		if (!input.empty() && !is_onlydigits(input))
		{
			cin.clear();
			cout << "Phone number must be fully composed by numbers" << endl;
			continue;
		}
		new_contact.setPhoneNumber(input);
		break;
	}

	cout << "Darkest secret 🕵️‍♂️ (yes, we promise not to tell anyone 🤭): ";
	getline(cin, input);
	new_contact.setDarkestSecret(input);

	if (count > MAX_CONTACT_INDEX)
		this->contacts[count - 1] = new_contact;
	else
	{
		this->count += 1;
		this->contacts[count - 1] = new_contact;
	}
	cout << "Contact added successfully ✅" << endl;
}

void PhoneBook::searchContact(void)
{
	if (count == 0)
	{
		cout << "There are no contacts to display! ❌" << endl;
		return ;
	}
	cout << "\n|     Index|First Name| Last Name|  Nickname|" << endl;
	for (size_t i = 0; i < this->count; i += 1)
	{
		cout << "|" << std::right << std::setw(10) << i << "|";
		cout << std::right << std::setw(10) << get_formatted_field(contacts[i].getFirstName()) << "|" ;
		cout << std::right << std::setw(10) << get_formatted_field(contacts[i].getLastName()) << "|";
		cout << std::right << std::setw(10) << get_formatted_field(contacts[i].getNickname()) << "|";
		cout << endl;
	}

	string index;
	int conv_index;

	while (1)
	{
		cout << "Please insert the index of the contact you'd like to display: ";
		getline(cin, index);
		if (!index.empty() && is_onlydigits(index))
		{
			conv_index = atoi(index.c_str());
			if (conv_index <= MAX_CONTACT_INDEX)
				break;
		}
		cin.clear();
		cout << "Invalid input" << endl;
	}
	if ((size_t)conv_index > (count - 1))
		cout << "There's no contact with that index 📘" << endl;
	else
		display_contact_info(this->contacts[conv_index]);
}
