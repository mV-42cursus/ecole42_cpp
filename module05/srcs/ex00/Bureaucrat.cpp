#include "Bureaucrat.hpp"

// OCCF
Bureaucrat::Bureaucrat() {
	std::cout << "[Bureaucrat] Default Constructor called." << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "[Bureaucrat] Destructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {
	std::cout << "[Bureaucrat] Copy Constructor called." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this == &other)
		return *this;
	this->name = other.name;
	this->grade = other.grade;
	return *this;
}

// CONSTRUCTORS
Bureaucrat::Bureaucrat(const std::string& newName, int newGrade) : name(newName), grade(newGrade) {
	std::cout << "[Bureaucrat] Parameterized Constructor called." << std::endl;
}

// ACCESSORS [GETTERS && SETTERS]
std::string Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

// METHOD || MEMBER FUNCTIONS
void Bureaucrat::incrementGrade() {
	if (grade <= maxGrade) throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade() {
	if (grade >= minGrade) throw GradeTooLowException();
	grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low.";
}

// OPERATOR OVERLOADING
std::ostream& operator<<(std::ostream &os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() <<  ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return os;
}
