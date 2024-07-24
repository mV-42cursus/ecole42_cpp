#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	{
		std::cout << "============ [ShrubeeryCreationForm] ============      (s, e) :: (145, 137)" << std::endl;
		try {
			int grade = 137;
			Bureaucrat employee("[신입직원1]", grade);
			AForm* form = new ShrubberyCreationForm("[ShrubberyCreationForm]");
			employee.signForm(*form);
			form->execute(employee);
			delete form;
		}	catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "============= [RobotomyRequestForm] =============      (s, e) :: (72, 45)" << std::endl;
		try {
			int grade = 45;
			Bureaucrat employee("[신입직원2]", grade);
			AForm* form = new RobotomyRequestForm("[RobotomyRequestForm]");
			employee.signForm(*form);
			form->execute(employee);
			delete form;
		}	catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "=========== [PresidentialPardonForm] ===========       (s, e) :: (25, 5)" << std::endl;
		try {
			int grade = 5;
			Bureaucrat employee("[신입직원3]", grade);
			AForm* form = new PresidentialPardonForm("[PresidentialPardonForm]");
			employee.signForm(*form);
			form->execute(employee);
			delete form;
		}	catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "=========== [Intern] ===========" << std::endl;
		Intern bottomOfTheFoodChain;
		try {
			int grade = 5;
			Bureaucrat employee("[신입직원4]", grade);
			try {
				AForm* form = bottomOfTheFoodChain.makeForm("Shruberry request", "<Target>");
				employee.signForm(*form);
				// form->execute(employee);
				delete form;
			}	catch (std::exception& e) {
				std::cout << e.what() << std::endl;
			}
		}	catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
}
