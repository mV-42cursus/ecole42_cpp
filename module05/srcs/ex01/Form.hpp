#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
private:
	const				std::string name;
	bool				signature;
	int const			grade_required_to_sign;
	int const			grade_required_to_execute;
	static const int	maxGrade = 1;
	static const int	minGrade = 150;
	Form();
public:
	// OCCF
	~Form();
	Form(const Form& other);
	Form& operator=(const Form& other);

	// CONSTRUCTORS
	Form(const std::string& name, int const signGrade, int const executeGrade);

	// ACCESSORS [GETTER && SETTER]
	std::string getName() const;
	bool getSignature() const;
	int getSignGrade() const;
	int getExecuteGrade() const;

	// METHOD || MEMBER FUNCS
	void beSigned(Bureaucrat &bureaucrat);

	// EXCEPTION
	class GradeTooHighException : public std::exception 
	{
	public:
		char const* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		char const* what() const throw();
	};
};

// OPERATOR OVERLOADING
std::ostream& operator<<(std::ostream& os, const Form& other);

#endif