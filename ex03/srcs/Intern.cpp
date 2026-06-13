#include "Intern.hpp"

Intern::Intern() {}

//Nothing to copy; (void)other to mute warnings
Intern::Intern(const Intern &other) {(void)other;}

Intern& Intern::operator=(const Intern &other) {(void) other; return *this;}

Intern::~Intern() {}


AForm* Intern::createShrubbery(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string &target) {
    return new PresidnetialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) {

    std::string types[] = {
        "shrubbery creation",
        "robotomy request",
        "presidnetial pardon"
    };

    AForm* (Intern::*createList[])(const std::string &) = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

    for (int i = 0; i < 3; i++) {
        if (types[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*createList[i])(target);
        }
    }

    std::cout << "Error: Intern cannot create form '" << formName << "' because the type is unknown." << std::endl;
    return NULL;
}