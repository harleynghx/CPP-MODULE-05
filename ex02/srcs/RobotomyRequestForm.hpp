#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
   const std::string _target;
   RobotomyRequestForm();

public:
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();

    RobotomyRequestForm(const std::string target);

    void execute(const Bureaucrat &b) const;
};

#endif