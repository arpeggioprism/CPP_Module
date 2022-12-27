#pragma once
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int contactCount;
	bool isFull;

public:
	PhoneBook();
	void add(Contact contact);
	void exit();
	void search();
	void display();
};
