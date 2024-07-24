#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>

class AForm;
class Bureaucrat
{
	private:
		std::string name;
		int grade;
		static const int maxGrade = 1;
		static const int minGrade = 150;
		Bureaucrat();
	
	public:
		// OCCF
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat& other);

		// CONSTRUCTORS
		Bureaucrat(const std::string& newName, int newGrade);

		// ACCESSORS [GETTERS && SETTERS]
		std::string getName() const;
		int getGrade() const;

		// METHOD || MEMBER FUNCTIONS
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm& form);
		void executeForm(AForm const& form);
	
	public:
		// EXCEPTION
		class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
		};
};

// OPERATOR OVERLOADING
std::ostream& operator<<(std::ostream &os, const Bureaucrat& other);

#endif