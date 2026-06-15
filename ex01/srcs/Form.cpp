#include "Form.hpp"
#include "Bureaucrat.hpp"

// Default constructor
Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

// Parameterized constructor
Form::Form(std::string const name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

// Copy constructor
Form::Form(const Form &other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

// Assignment operator (only _isSigned can be copied, const members cannot)
Form& Form::operator=(const Form &other) {
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

Form::~Form() {}

// Getters
std::string Form::getName() const       { return _name; }
bool        Form::getIsSigned() const   { return _isSigned; }
int         Form::getGradeToSign() const    { return _gradeToSign; }
int         Form::getGradeToExecute() const { return _gradeToExecute; }

// beSigned: signs the form if the bureaucrat's grade is high enough
void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();
    _isSigned = true;
}

// Exception messages
const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high! Maximum grade is 1.";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low! Minimum grade is 150.";
}

// Stream overload
std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form: " << f.getName()
       << " | Signed: " << (f.getIsSigned() ? "Yes" : "No")
       << " | Grade to sign: " << f.getGradeToSign()
       << " | Grade to execute: " << f.getGradeToExecute();
    return os;
}
