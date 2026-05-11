#include "Bureaucrat.hpp"

int main() {
    std::cout << "--- Testing Valid Bureaucrats ---" << std::endl;
    try {
        Bureaucrat b1("Alice", 1);
        std::cout << b1 << std::endl;
        
        Bureaucrat b2("Bob", 150);
        std::cout << b2 << std::endl;
        
        Bureaucrat b3("Charlie", 42);
        std::cout << b3 << std::endl;
        
        std::cout << "Charlie got promoted!" << std::endl;
        b3.incrementGrade();
        std::cout << b3 << std::endl;
        
        std::cout << "Charlie got demoted..." << std::endl;
        b3.decrementGrade();
        std::cout << b3 << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing Grade Too High Exception (Constructor) ---" << std::endl;
    try {
        Bureaucrat b_invalid("TooHigh", 0);
        std::cout << b_invalid << std::endl; // Should not reach here
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing Grade Too Low Exception (Constructor) ---" << std::endl;
    try {
        Bureaucrat b_invalid("TooLow", 151);
        std::cout << b_invalid << std::endl; // Should not reach here
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing Increment Exception ---" << std::endl;
    try {
        Bureaucrat b("TopDog", 1);
        std::cout << b << std::endl;
        std::cout << "Trying to promote past grade 1..." << std::endl;
        b.incrementGrade();
        std::cout << b << std::endl; // Should not reach here
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing Decrement Exception ---" << std::endl;
    try {
        Bureaucrat b("UnderDog", 150);
        std::cout << b << std::endl;
        std::cout << "Trying to demote past grade 150..." << std::endl;
        b.decrementGrade();
        std::cout << b << std::endl; // Should not reach here
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
