#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main() {
    std::srand(std::time(NULL));

    std::cout << "==========================================" << std::endl;
    std::cout << "      TESTING EX03: INTERN                " << std::endl;
    std::cout << "==========================================" << std::endl;

    Intern someRandomIntern;
    Bureaucrat boss("President Zaphod", 1);

    AForm* rrf = NULL;

    std::cout << "\n--- Test 1: Intern creates robotomy request ---" << std::endl;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        std::cout << *rrf << std::endl;
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
        rrf = NULL;
    }

    std::cout << "\n--- Test 2: Intern creates shrubbery creation ---" << std::endl;
    rrf = someRandomIntern.makeForm("shrubbery creation", "garden");
    if (rrf) {
        std::cout << *rrf << std::endl;
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
        rrf = NULL;
    }

    std::cout << "\n--- Test 3: Intern creates presidential pardon ---" << std::endl;
    rrf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    if (rrf) {
        std::cout << *rrf << std::endl;
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
        rrf = NULL;
    }

    std::cout << "\n--- Test 4: Intern tries to create invalid form ---" << std::endl;
    rrf = someRandomIntern.makeForm("coffee making", "Jimmy");
    if (rrf) {
        std::cout << "Error: This should not have been created!" << std::endl;
        delete rrf;
    } else {
        std::cout << "Success: Returned NULL for unknown form type." << std::endl;
    }

    std::cout << "\n==========================================" << std::endl;
    std::cout << "      TESTING EX03 COMPLETE               " << std::endl;
    std::cout << "==========================================" << std::endl;

    return 0;
}
