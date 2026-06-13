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

    

};


#endif AFORM_HPP