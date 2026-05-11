#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "--- Testing Valid Form Creation ---" << std::endl;
    try {
        Form f1("Tax Return", 50, 25);
        std::cout << f1 << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing Form Grade Too High (grade 0) ---" << std::endl;
    try {
        Form f_invalid("BadForm", 0, 25);
        std::cout << f_invalid << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing Form Grade Too Low (grade 151) ---" << std::endl;
    try {
        Form f_invalid("BadForm", 151, 25);
        std::cout << f_invalid << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing beSigned: Bureaucrat grade high enough ---" << std::endl;
    try {
        Bureaucrat b("Alice", 30);
        Form f("Tax Return", 50, 25);
        std::cout << f << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing beSigned: Bureaucrat grade too low ---" << std::endl;
    try {
        Bureaucrat b("Bob", 100);
        Form f("Top Secret", 10, 5);
        std::cout << f << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
