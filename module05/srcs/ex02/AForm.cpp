#include "AForm.hpp"

// OCCF
AForm::~AForm() {
	std::cout << "[AForm] Destructor called." << std::endl;
}

AForm::AForm(const AForm& other) :
 	name(other.name), 
	signature(other.signature), 
	grade_required_to_sign(other.grade_required_to_sign), 
	grade_required_to_execute(other.grade_required_to_execute) 
{
	std::cout << "[AForm] Copy Constructor called." << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	if (this == &other)
		return *this;
	const_cast<std::string&>(this->name) = other.name;
	this->signature = other.signature;
	const_cast<int&>(grade_required_to_sign) = other.grade_required_to_sign;
	const_cast<int&>(grade_required_to_execute) = other.grade_required_to_execute;
	return *this;
}

// CONSTRUCTORS
AForm::AForm(const std::string& name, int const gradeRequiredToSign, int const gradeRequiredToExecute) :
	name(name),
	signature(false),
	grade_required_to_sign(gradeRequiredToSign),
	grade_required_to_execute(gradeRequiredToExecute)
{
	if (this->grade_required_to_sign < this->maxGrade || this->grade_required_to_execute < this->maxGrade)
		throw GradeTooHighException();
	if (this->grade_required_to_sign > this->minGrade || this->grade_required_to_execute > this->minGrade)
		throw GradeTooLowException();
}

// ACCESSORS [GETTER && SETTER]
std::string AForm::getName() const {
	return this->name;
}

bool AForm::getSignature() const {
	return this->signature;
}

int AForm::getGradeRequiredToSign() const {
	return this->grade_required_to_sign;
}

int AForm::getGradeRequiredToExecute() const {
	return this->grade_required_to_execute;
}

// METHOD || MEMBER FUNCTIONS
void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > grade_required_to_sign)
		throw GradeTooLowException();
	this->signature = true;
}

// EXCEPTION
char const* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high.";
}

char const* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low.";
}

const char* AForm::GradeNotSignedException::what() const throw() {
	return "Grade not signed.";
}