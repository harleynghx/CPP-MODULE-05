#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::srand(std::time(NULL));

    std::cout << "==========================================" << std::endl;
    std::cout << "      TESTING EX02: CONCRETE FORMS        " << std::endl;
    std::cout << "==========================================" << std::endl;

    // Create Bureaucrats
    Bureaucrat boss("President Zaphod", 1);
    Bureaucrat middle("Manager Bob", 50);
    Bureaucrat intern("Intern Jimmy", 150);

    std::cout << "\n--- Bureaucrats Created ---" << std::endl;
    std::cout << boss << std::endl;
    std::cout << middle << std::endl;
    std::cout << intern << std::endl;

    // Create Forms
    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    std::cout << "\n--- Forms Created ---" << std::endl;
    std::cout << shrubbery << std::endl;
    std::cout << robotomy << std::endl;
    std::cout << pardon << std::endl;

    std::cout << "\n==========================================" << std::endl;
    std::cout << "   TEST 1: EXECUTE UNSIGNED FORMS         " << std::endl;
    std::cout << "==========================================" << std::endl;

    boss.executeForm(shrubbery);
    boss.executeForm(robotomy);
    boss.executeForm(pardon);

    std::cout << "\n==========================================" << std::endl;
    std::cout << "   TEST 2: SIGNING FORMS WITH LOW GRADE   " << std::endl;
    std::cout << "==========================================" << std::endl;

    intern.signForm(shrubbery);
    intern.signForm(robotomy);
    intern.signForm(pardon);

    std::cout << "\n==========================================" << std::endl;
    std::cout << "   TEST 3: SIGNING FORMS SUCCESSFULLY     " << std::endl;
    std::cout << "==========================================" << std::endl;

    middle.signForm(shrubbery); // Required: 145. Manager grade: 50. Success.
    middle.signForm(robotomy);  // Required: 72. Manager grade: 50. Success.
    boss.signForm(pardon);      // Required: 25. Boss grade: 1. Success.

    std::cout << "\n--- Forms status after signing ---" << std::endl;
    std::cout << shrubbery << std::endl;
    std::cout << robotomy << std::endl;
    std::cout << pardon << std::endl;

    std::cout << "\n==========================================" << std::endl;
    std::cout << "   TEST 4: EXECUTION WITH LOW GRADE       " << std::endl;
    std::cout << "==========================================" << std::endl;

    // Shrubbery exec: 137. Jimmy: 150. Failure.
    intern.executeForm(shrubbery);
    // Robotomy exec: 45. Bob: 50. Failure.
    middle.executeForm(robotomy);
    // Pardon exec: 5. Bob: 50. Failure.
    middle.executeForm(pardon);

    std::cout << "\n==========================================" << std::endl;
    std::cout << "   TEST 5: EXECUTION SUCCESSFULLY         " << std::endl;
    std::cout << "==========================================" << std::endl;

    // Shrubbery exec: 137. Bob: 50. Success.
    middle.executeForm(shrubbery);
    std::cout << std::endl;

    // Robotomy exec: 45. Boss: 1. Success.
    // Let's run it multiple times to observe the 50% success rate
    for (int i = 0; i < 4; i++) {
        boss.executeForm(robotomy);
        std::cout << std::endl;
    }

    // Pardon exec: 5. Boss: 1. Success.
    boss.executeForm(pardon);

    std::cout << "\n==========================================" << std::endl;
    std::cout << "      TESTING EX02 COMPLETE               " << std::endl;
    std::cout << "==========================================" << std::endl;

    return 0;
}
