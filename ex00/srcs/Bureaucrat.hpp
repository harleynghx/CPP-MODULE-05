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
    // OCF
    Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    // getters
    std::string getName() const;
    int getGrade() const;

    // ++ && --
    void incrementGrade() ;
    void decrementGrade() ;


    // custom exception class ( inherit from std::exception )
    // public inheritance =  "is a" relationship ( else compiler won't know ur custom exception is part of std::exception )
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};
// return ostream& to allow chaining ( cout << b1 << b2 << endl )
std::ostream &operator<<(std::ostream &os, Bureaucrat const &b);
#endif