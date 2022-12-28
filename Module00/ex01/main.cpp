#include "PhoneBook.hpp"

int main(void)
{
	int			choice;
	PhoneBook	phoneBook = PhoneBook();
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
	Contact		contact;

	while (1)
	{ 
		std::cout << "#############################" << std::endl;
		std::cout << "#   Select:                 #" << std::endl;
		std::cout << "#   [1] Add a contact       #" << std::endl;
		std::cout << "#   [2] Search contacts     #" << std::endl;
		std::cout << "#   [3] Exit                #" << std::endl;
		std::cout << "#############################" << std::endl;
		std::cout << "input: ";
		std::cin >> choice;
		if (std::cin.fail())
		{
			std::cerr << "Invalid input" << std::endl;
			exit(1);
		}
		switch (choice)
		{
			case 1:
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Enter the first name: ";
				getline(std::cin, firstName);
				contact.setFirstName(firstName);
				std::cout << "Enter the last name: ";
				getline(std::cin, lastName);
				contact.setLastName(lastName);
				std::cout << "Enter the nickname: ";
				getline(std::cin, nickName);
				contact.setNickName(nickName);
				std::cout << "Enter the phone number: ";
				getline(std::cin, phoneNumber);
				contact.setPhoneNumber(phoneNumber);
				std::cout << "Enter the darkest secret: ";
				getline(std::cin, darkestSecret);
				contact.setDarkestSecret(darkestSecret);
				phoneBook.add(contact);
				break ;
			case 2:
				phoneBook.search();
				break;
			case 3:
				phoneBook.exit();
				break ;
		}
	}
	return 0;
}