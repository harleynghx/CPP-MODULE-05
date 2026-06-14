#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const AForm &other) 
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm& AForm::operator=(const AForm &other) {
    if(this != &other)
        _isSigned = other._isSigned;
    return *this;
}
AForm::~AForm() {}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) 
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}
std::string AForm::getName() const {return _name ;}

bool AForm::getIsSigned() const {return _isSigned;}

int AForm::getGradeToSigned() const {return _gradeToSign;}

int AForm::getGradeToExecute() const {return _gradeToExecute;}

void AForm::beSigned(const Bureaucrat &b) {
    if(b.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    _isSigned = true;
}

// check _isSigned == true && grade is enough to execute
void AForm::checkRequirements (const Bureaucrat &b) const {
    if(_isSigned == false)
        throw AForm::NotSignedException();
}
