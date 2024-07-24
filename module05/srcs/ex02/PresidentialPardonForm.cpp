#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
	:	AForm(other.getName(), other.getGradeRequiredToSign(), other.getGradeRequiredToExecute())
	,	_target(other._target)
	{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	:	AForm(target, 25, 5)
	,	_target(target)
	{}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (this->getSignature() == false)
		throw GradeNotSignedException();
	if (executor.getGrade() > this->getGradeRequiredToExecute())
		throw GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
