#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    const std::string _target;
    PresidentialPardonForm(); 
   
public:
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();

    PresidentialPardonForm(const std::string target);

    void execute(const Bureaucrat &b) const;

};

#endif