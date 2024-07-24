#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() : last_contact_idx(-1), number_of_contacts(0) {}
PhoneBook::~PhoneBook() {}

int		 PhoneBook::getContactCnt() const { return this->number_of_contacts; };
int		 PhoneBook::getLastContactIdx() { return this->last_contact_idx; };
Contact  PhoneBook::getNthContact(int idx) const { return contacts[idx]; };

void	PhoneBook::setLastContactIdx(int x) { this->last_contact_idx = x; };
void	PhoneBook::setContactCnt(int x) { this->number_of_contacts = x; };

void	PhoneBook::add(Contact newContact)
{
	int targetIdx = (getLastContactIdx() + 1) % 8;

	setLastContactIdx(targetIdx);
	contacts[last_contact_idx] = newContact;
	if (number_of_contacts < 8)
		number_of_contacts++;
}

std::string strFormat(std::string str)
{
	if (str.length() > 10)
	{
		str[9] = '.';
		str.erase(10);
	}
	return str;
}

void	PhoneBook::display() const
{
	int columnWidth = 10;
	std::cout << std::right << std::setfill(' ')
		<< std::setw(columnWidth) << "Index" << " | "
		<< std::setw(columnWidth) << "First Name" << " | "
		<< std::setw(columnWidth) << "Last Name" << " | "
		<< std::setw(columnWidth) << "Nick Name" << " | "
		<< std::setw(columnWidth) << "Phone Number"
		<< std::endl;
	for (int idx = 0; idx < getContactCnt(); idx++) {
		std::cout << std::right << std::setfill(' ')
			<< std::setw(columnWidth) << idx << " | "
			<< std::setw(columnWidth) << strFormat(getNthContact(idx).getFirstName()) << " | "
			<< std::setw(columnWidth) << strFormat(getNthContact(idx).getLastName()) << " | "
			<< std::setw(columnWidth) << strFormat(getNthContact(idx).getNickName()) << " | "
			<< std::setw(columnWidth) << strFormat(getNthContact(idx).getPhoneNumber())
			<< std::endl;
	}
}

void	PhoneBook::fetchData(int idx) const
{
	std::cout
		<< "[First Name] : " << this->contacts[idx].getFirstName() << std::endl
		<< "[Last Name] : " << this->contacts[idx].getLastName() << std::endl
		<< "[Nick Name] : " << this->contacts[idx].getNickName() << std::endl
		<< "[Phone Number] : " << this->contacts[idx].getPhoneNumber() << std::endl
		<< "[Darkest Secret] : " << this->contacts[idx].getDarkestSecret() << std::endl;
}

void	PhoneBook::search()
{
	std::string str_idx;
	int		 idx = 0;

	while (1)
	{
		std::cout << "Please enter the index you would like to discover : ";
		std::getline(std::cin, str_idx);
		if (std::cin.eof())
		{
			clearerr(stdin);
			std::cin.clear();
			std::cout << std::endl;
			continue;
		}
		std::stringstream ss(str_idx);
		ss >> idx;
		if (ss.fail()) {
			std::cout << "Enter numeric values only." << std::endl;
			idx = 0;
			continue ;
		}
		else if (idx >= this->getContactCnt() || idx < 0)
		{
			std::cout << "Invalid index [" << idx << "] try again..." << std::endl;
			idx = 0;
			continue ;
		}
		else
			break ;
	}
	this->fetchData(idx);
}
