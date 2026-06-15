#include "PresidentialPardonForm.hpp"

// PresidentialPardonForm::PresidentialPardonForm()
//     : AForm("PresidentialPardonForm", 25, 5), _target("default target") {
// }
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    (void)other;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm () {}


PresidentialPardonForm::PresidentialPardonForm(const std::string target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

