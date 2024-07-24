#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	std::string command;
	PhoneBook phoneBook;
	Contact contact;

	while (true)
	{
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
		if (std::cin.eof()) 
		{
			clearerr(stdin);
			std::cin.clear();
			std::cout << std::endl;
			continue ;
		}
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
			phoneBook.add(contact.add());
		else if (command == "SEARCH")
		{
			if (phoneBook.getContactCnt() == 0) {
				std::cout << "Phone book is currently empty." << std::endl;
				continue ;
			}
			phoneBook.display();
			phoneBook.search();
		}
		else if (command.length() == 0)
			continue ;
		else 
			std::cout << "Invalid command." << std::endl;
	}
	return 0;
}
