#pragma once
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <sstream>
class PhoneBook
{
private:
	static const int MAX = 8;

	Contact contacts[MAX];
	int	last_contact_idx;
	int number_of_contacts;
public:
	PhoneBook();
	~PhoneBook();

	void		setContactCnt(int x);
	void		setLastContactIdx(int x);
	int 		getContactCnt() const;
	int 		getLastContactIdx();
	Contact		getNthContact(int idx) const;

	void 	add(Contact contact);
	void 	display() const;
	void	search();
	void	fetchData(int idx) const;
};

#endif