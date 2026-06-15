#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    (void)other;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &b) const {
    this->checkRequirements(b);
    
    std::cout << "* drilling noises *" << std::endl;
    if ((std::rand() & 1) == 0) {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "The robotomy of " << _target << " failed." << std::endl;
    }
}
