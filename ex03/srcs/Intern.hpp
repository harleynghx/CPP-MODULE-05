#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
private:
    AForm* createShruberry(std::string const &target);
    AForm* createRobotomy(std::string const &target);
    AForm* createPresidential(std::string const &target);
      
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(std::string const & formName, std::string const & target);




};
#endif