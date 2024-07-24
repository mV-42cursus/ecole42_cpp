#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm
{
protected:
	const std::string name;
	bool signature;
	int const grade_required_to_sign;
	int const grade_required_to_execute;
	static const int maxGrade = 1;
	static const int minGrade = 150;
	AForm();
public:
	// OCCF
	virtual ~AForm();
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);

	// CONSTRUCTORS
	AForm(const std::string& name, int const gradeRequiredToSign, int const gradeRequiredToExecute);

	// ACCESSORS [GETTER && SETTER]
	std::string getName() const;
	bool getSignature() const;
	int getGradeRequiredToSign() const;
	int getGradeRequiredToExecute() const;

	// METHOD || MEMBER FUNCS
	void beSigned(Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const& executor) const = 0;

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

	class GradeNotSignedException : public std::exception 
	{
		public:
			const char* what() const throw();
	};
};

#endif