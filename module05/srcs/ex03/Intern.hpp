#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		Intern(Intern const& other);
		Intern& operator=(Intern const& other);
		AForm* createShrubberyForm(const std::string& target);
		AForm* createRobotomyRequestForm(const std::string& target);
		AForm* createPresidentialPardonForm(const std::string& target);

	public:
		Intern();
		~Intern();

	public:
		typedef AForm* (Intern::*targetForm)(const std::string& target);
		AForm* makeForm(const std::string& form, const std::string& target);

	public:
		class TypeError : public std::exception
		{
			private:
				const char* err_msg;
			public:
				TypeError();
				const char* what() const throw();
		};
};

#endif
