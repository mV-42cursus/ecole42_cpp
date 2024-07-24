#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

#include <cstdlib>
#include <ctime>

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
	:	AForm(other.getName(), other.getGradeRequiredToSign(), other.getGradeRequiredToExecute())
	,	_target(other._target)
	{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	:	AForm(target, 72, 45)
	,	_target(target)
	{}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (this->getSignature() == false)
		throw GradeNotSignedException();
	if (executor.getGrade() > this->getGradeRequiredToExecute())
		throw GradeTooLowException();

	// initialize random number generator
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	int possibility = std::rand() % 2;
	std::cout << "clack - clack - clack" << std::endl;
	if (possibility)
		std::cout << this->_target << " has been successfully robotized." << std::endl;
	else
		std::cout << this->_target << " robotomy failed." << std::endl;
}
