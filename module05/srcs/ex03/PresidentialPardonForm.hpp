#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class AForm;
class Bureaucrat;

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;
	PresidentialPardonForm();
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
public:
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	virtual ~PresidentialPardonForm();
	void execute(Bureaucrat const& executor) const;
};	

#endif