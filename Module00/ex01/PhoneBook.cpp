#pragma once
#include "PhoneBook.hpp"

void PhoneBook::add(Contact contact)
{
	if (this->contactCount == 8)
	{
		this->contactCount = 0;
		this->isFull = true;
	}
	this->contacts[contactCount] = contact;
	this->contactCount++;
}