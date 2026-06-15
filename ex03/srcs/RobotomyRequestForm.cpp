#include "RobotomyRequestForm.hpp"

class RobotomyRequestForm : public AForm {
private:
   const std::string _target;
   RobotomyRequestForm();

public:
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();

    RobotomyRequestForm(const std::string target);

    void execute(const Bureaucrat &b);
};
