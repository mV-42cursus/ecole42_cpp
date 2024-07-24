#include "Intern.hpp"

Intern::Intern() {}
Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& form, const std::string& target) {
	// mapping functions via function pointer
	targetForm format[] = {
		&Intern::createShrubberyForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};

	std::string validFormCandidates[3] = {
		"Shruberry request",
		"Robotomy request",
		"Presidential pardon request"
	};

	int i = 0;
	for (i=0; i<3; i++) {
		if (form == validFormCandidates[i]) {
			std::cout << "Intern successfully created <" << form << "> form" << std::endl;
			return (this->*format[i])(target);
		}
	}

	throw TypeError();
}

AForm* Intern::createShrubberyForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}

Intern::TypeError::TypeError()
	: err_msg("Wrong format")
	{}

const char* Intern::TypeError::what() const throw() {
	return err_msg;
}
