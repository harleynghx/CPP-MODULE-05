#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Form; // forward declaration : solve circular dependency


class Bureaucrat {
    private:
        const std::string   _name;
        int                 _grade;

    public:
        Bureaucrat(std::string const name, int grade);
        //OCF
        Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat& operator=(const Bureaucrat &other);
        ~Bureaucrat();

        std::string getName() const;
        int         getGrade() const;

        void incrementGrade();
        void decrementGrade();
        
        void signForm(Form &f);

        class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw() {return "Grade is too high! Maximum grade is 1.";}
        };

        class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw() {return "Grade is too low! Minimum grade is 150.";}
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
