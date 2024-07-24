#pragma once
#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <cstdio>

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;

public:
	Contact();
	~Contact();

	void setFirstName(const std::string& firstName);
	void setLastName(const std::string& lastName);
	void setNickName(const std::string& nickName);
	void setPhoneNumber(const std::string& phoneNumber);
	void setDarkestSecret(const std::string& darkestSecret);

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;

	Contact add();
	static bool isValidPhoneNumber(const std::string& phone); // static => removes the dependecies to the instance
};

#endif