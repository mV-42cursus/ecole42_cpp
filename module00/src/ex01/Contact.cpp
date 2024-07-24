#include "Contact.hpp"
#include "PhoneBook.hpp"

Contact::Contact() {}
Contact::~Contact() {}

void Contact::setFirstName(const std::string& firstName) { first_name = firstName; };
void Contact::setLastName(const std::string& lastName) { last_name = lastName; };
void Contact::setNickName(const std::string& nickName) { nick_name = nickName; };
void Contact::setPhoneNumber(const std::string& phoneNumber) { phone_number = phoneNumber; };
void Contact::setDarkestSecret(const std::string& darkestSecret) { darkest_secret = darkestSecret; };

std::string Contact::getFirstName() const { return first_name; };
std::string Contact::getLastName() const { return last_name; };
std::string Contact::getNickName() const { return nick_name; };
std::string Contact::getPhoneNumber() const { return phone_number; };
std::string Contact::getDarkestSecret() const { return darkest_secret; };

bool Contact::isValidPhoneNumber(const std::string& phone) {
	for (std::string::size_type i = 0; i < phone.length(); ++i) {
		char c = phone[i];
		if (!isdigit(c))
			return false;
	}
	return true;
}

Contact Contact::add()
{
	Contact newContact;

	std::string dataElements[5] = {
		"first name",
		"last name",
		"nick name",
		"phone number",
		"darkest secret"
	};

	std::string input;
	for (int i = 0; i < 5; i++)	{
		std::cout << "Enter " << dataElements[i] << " : ";
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			clearerr(stdin);
			std::cin.clear();
			std::cout << std::endl;
			i--;
			continue ;
		}
		if (input.length() == 0) {
			i--;
			continue ;
		}
		switch (i) {
			case 0:
				newContact.setFirstName(input);
				break ;
			case 1:
				newContact.setLastName(input);
				break ;
			case 2:
				newContact.setNickName(input);
				break ;
			case 3:
				newContact.setPhoneNumber(input);
				if (Contact::isValidPhoneNumber(input) == false) {
					std::cout << "Invalid format, please try again." << std::endl;
					i--;
				}
				break ;
			case 4:
				newContact.setDarkestSecret(input);
				break ;
			default:
				break ;
		}
	}
	return newContact;
}