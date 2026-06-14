#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat {
private:
      const std::string _name;
      int _grade;

public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    Bureaucrat(const std::string name, int grade);

    std::string getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    void signForm(AForm &f);
    void executeForm(const AForm &f);

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw() {
            return "Bureaucrat grade is too high!";
        };
    };

    class GradeTooLowException : public std::exception {
    public :
        const char *what() const throw() {
            return "Bureaucrat grade is too low!";
        };
    };

};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b);

#endif