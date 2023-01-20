#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iomanip>
#include <iostream>

class	Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	std::string getFirstName();
	std::string getLastName();
	std::string getNickName();
	std::string getPhoneNumber();
	std::string getDarkestSecret();

	Contact();
	Contact(std::string fname, std::string lname, std::string nname, \
	std::string pnumber, std::string dsecret);

	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setNickName(std::string nickName);
	void setPhoneNumber(std::string phoneNumber);
	void setDarkestSecret(std::string darkestSecret);
};
#endif
