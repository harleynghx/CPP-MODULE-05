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

    //= 0 makes it a true virtual
    virtual void execute(const Bureaucrat &executor) const = 0;

    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSigned() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat &b);
    void checkRequirements(const Bureaucrat &b) const;

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw() {
            return "AForm grade is too high!";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw(){
            return "AForm grade is too low!";
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