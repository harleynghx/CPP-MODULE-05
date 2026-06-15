#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    (void)other;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) 
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}


void ShrubberyCreationForm::execute(const Bureaucrat &b) const {
    // Validates signature and grade requirements first
    this->checkRequirements(b);
    
    std::string filename = this->_target + "_shrubbery";
    std::ofstream file(filename.c_str());
    
    //Throw an exception on failure instead of printing to cerr
    if (!file.is_open()) {
        throw std::runtime_error("cannot open file for writing");
    }
    
    file << "      /\\      " << std::endl;
    file << "     /\\*\\     " << std::endl;
    file << "    /\\O\\*\\    " << std::endl;
    file << "   /*/\\/\\/\\   " << std::endl;
    file << "  /\\*\\/\\*\\/\\  " << std::endl;
    file << " /\\O\\/\\/*/\\/\\ " << std::endl;
    file << "       ||       " << std::endl;
    
    file.close();
}
