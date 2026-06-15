#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <fstream>
#include "AForm.hpp"



class ShrubberyCreationForm : public AForm {
private:
    const std::string _target;
    ShrubberyCreationForm();
      
public:
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();

    void execute(const Bureaucrat &b) const;
};



#endif