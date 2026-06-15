#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat; // forward declaration to avoid circular include

class Form
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExecute;

    public:
        Form(std::string const name, int gradeToSign, int gradeToExecute);
        Form();
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        std::string getName() const;
        bool        getIsSigned() const;
        int         getGradeToSign() const;
        int         getGradeToExecute() const;

        void beSigned(const Bureaucrat& b);

        class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif