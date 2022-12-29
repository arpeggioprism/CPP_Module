#pragma once
#include <iomanip>
#include <iostream>
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