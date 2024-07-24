#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class AForm;
class Bureaucrat;

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
	RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
public:
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	virtual ~RobotomyRequestForm();
	void execute(Bureaucrat const& executor) const;
};	

#endif