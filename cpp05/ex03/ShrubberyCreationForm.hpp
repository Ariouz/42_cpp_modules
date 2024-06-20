#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm(const std::string& _target);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();

        void    execute(const Bureaucrat& bureau) const;

    private:
        std::string _target;
};

#endif