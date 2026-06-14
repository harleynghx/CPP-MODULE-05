#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {
private:
   const std::string  _name;
   bool               _isSigned;
   const int          _gradeToSign;
   const int          _gradeToExecute;


public:
    AForm();
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    ~AForm();

    AForm(const std::string name, int gradeToSign, int gradeToExecute);

    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSigned() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat &b);

    //= 0 makes it a true virtual
    virtual void execute(const Bureaucrat &executor) const = 0;

    void checkRequirements(const Bureaucrat &executor) const;

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    class NotSignedException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm f);

#endif AFORM_HPP