#include "Form.hpp"

// OCCF
Form::~Form() {
	std::cout << "[Form] Destructor called." << std::endl;
}

Form::Form(const Form& other) :
	name(other.name), 
	signature(other.signature), 
	grade_required_to_sign(other.grade_required_to_sign), 
	grade_required_to_execute(other.grade_required_to_execute) 
{
	std::cout << "[Form] Copy Constructor called." << std::endl;
}

Form& Form::operator=(const Form& other) {
	if (this == &other)
		return *this;
	const_cast<std::string&>(this->name) = other.name;
	this->signature = other.signature;
	const_cast<int&>(grade_required_to_sign) = other.grade_required_to_sign;
	const_cast<int&>(grade_required_to_execute) = other.grade_required_to_execute;
	return *this;
}

// CONSTRUCTORS
Form::Form(const std::string& name, int const signGrade, int const executeGrade) :
	name(name),
	signature(false),
	grade_required_to_sign(signGrade),
	grade_required_to_execute(executeGrade)
{
	std::cout << "[Form] Parameterized Constructor called." << std::endl;
	if (this->grade_required_to_sign > this->minGrade || this->grade_required_to_execute > this->minGrade) {
		throw GradeTooLowException();
	}
	if (this->grade_required_to_sign < this->maxGrade || this->grade_required_to_execute < this->maxGrade)
		throw GradeTooHighException();
}

// ACCESSORS [GETTER && SETTER]
std::string Form::getName() const {
	return this->name;
}

bool Form::getSignature() const {
	return this->signature;
}

int Form::getSignGrade() const {
	return this->grade_required_to_sign;
}

int Form::getExecuteGrade() const {
	return this->grade_required_to_execute;
}

// METHOD || MEMBER FUNCTIONS
void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > grade_required_to_sign)
		throw GradeTooLowException();
	this->signature = true;
}

// EXCEPTION
char const* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high.";
}

char const* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low.";
}

// OPERATOR OVERLOADING
std::ostream& operator<<(std::ostream& os, const Form& form) {
	os 	<< "=========== [Form's Information] ===========" << std::endl
		<< "(Name) : " << form.getName() << std::endl;
	if (form.getSignature() == true)
		os << "(Signature) : signed" << std::endl;
	else
		os << "(Signature) : unsigned" << std::endl;
	os 	<< "(Required grade to sign) : " << form.getSignGrade() << std::endl
		<< "(Required grade to execute) : " << form.getExecuteGrade() << std::endl;
	os	<< "============================================" << std::endl;
	return os;
}
