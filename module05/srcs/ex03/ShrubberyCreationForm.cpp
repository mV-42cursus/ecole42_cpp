#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

// OCCF
ShrubberyCreationForm::~ShrubberyCreationForm() {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
	:   AForm(other.getName(), other.getGradeRequiredToSign(), other.getGradeRequiredToExecute())
	,   _target(other._target)
	{}

// CONSTRUCTORS
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
	:	AForm(target, 145, 137)
	,	_target(target) 
	{}

// METHOD || MEMBER FUNCTIONS
void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	if (this->getSignature() == false)
		throw GradeNotSignedException();
	if (executor.getGrade() > this->getGradeRequiredToExecute())
		throw GradeTooLowException();
	std::string filename = this->_target + "_shruberry";
	std::ofstream os(filename.c_str());
	if (!os.is_open())
		throw std::runtime_error("Failed to open file for writing: " + filename);
	std::cout << "A bureaucrat has executed ShrubberyCreationForm." << std::endl;
	std::cout << "Check your directory for a created file." << std::endl;
	os << "		/\\" << std::endl;
	os << "       /  \\" << std::endl;
	os << "      /\\  /\\" << std::endl;
	os << "     /  \\/  \\" << std::endl;
	os << "    /\\  /\\  /\\" << std::endl;
	os << "   /  \\/  \\/  \\" << std::endl;
	os << "  /\\  /\\  /\\  /\\" << std::endl;
	os << " /  \\/  \\/  \\/  \\" << std::endl;
	os << "/\\  /\\  /\\  /\\  /\\";
	os.close();
}
