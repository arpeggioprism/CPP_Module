#include "PhoneBook.hpp"

void PhoneBook::add(Contact contact)
{
	if (contactCount == 8)
	{
		contactCount = 0;
		isFull = true;
	}
	contacts[contactCount] = contact;
	contactCount++;
}

void PhoneBook::search()
{
	int limit = isFull ? 8 : contactCount;
	int index = 0;
	std::cout << std::setw(10) << "INDEX" << " | "
	<< std::setw(10) << "FIRST NAME" << " | "
	<< std::setw(10) << "LAST NAME" << " | "
	<< std::setw(10) << "NICKNAME" << std::endl;
	for (int i = 0; i < limit; i++)
	{
		std::cout << std::setw(10) << i
		<< std::setw(13) << contacts[i].getFirstName()
		<< std::setw(13) << contacts[i].getLastName()
		<< std::setw(13) << contacts[i].getNickName() << std::endl;
	}
	if (contactCount == 0)	
	{
		std::cout << "No contacts" << std::endl;
		return ;
	}
	std::cout << "INDEX : ";
	std::cin >> index;
	if (-1 < index && index < contactCount)
	{
		std::cout << "FIRST NAME: " << this->contacts[index].getFirstName() << std::endl
		<< "LAST NAME : " << this->contacts[index].getLastName() << std::endl
		<< "NICKNAME  : " << this->contacts[index].getNickName() << std::endl
		<< "PHONE NUM : " << this->contacts[index].getPhoneNumber() << std::endl
		<< "SECRET    : " << this->contacts[index].getDarkestSecret() << std::endl;
	}
	else
		std::cout << "No such contact" << std::endl;
}

void PhoneBook::exit()
{
	std::exit(0);
}

PhoneBook::PhoneBook()
{
	contactCount = 0;
	isFull = false;
	for (int i = 0; i < 8; i++)
		contacts[i] = Contact();
}
