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
    virtual ~AForm();

    AForm(const std::string name, int gradeToSign, int gradeToExecute);

    //= 0 makes it a true virtual
    virtual void execute(const Bureaucrat &executor) const = 0;

    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat &b);
    void checkRequirements(const Bureaucrat &b) const;

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw() {
            return "Grade is too high.";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw(){
            return "Grade is too low.";
        }
    };

    class NotSignedException : public std::exception {
    public:
        const char* what() const throw() {
            return "AForm is not signed!";
        }
    };
};

// stream insertion operator
std::ostream& operator<<(std::ostream& os, const AForm &f);

#endif