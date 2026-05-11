#ifndef BUREACRUT_HPP
#define BUREACRUT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat {
private:
   std::string const _name;
   int _grade;
public:
    Bureaucrat(std::string const name, int grade);
    Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;

    void incrementGrade() ;
    void decrementGrade() ;

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b);
#endif