#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Form
{

    public:
        Form(const std::string& name, int signGrade, int execGrade);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        const std::string&  getName(void) const;
        bool                isSigned(void) const;
        int                 getExecGrade(void) const;
        int                 getSignGrade(void) const;

        void                beSigned(const Bureaucrat& bureau);

        class GradeTooLowException : public std::exception
        {
            const char* what() const throw()
            {
                return "Form grade is too low.\n";
            }
        };

        class GradeTooHighException : public std::exception
        {
            const char* what() const throw()
            {
                return "Form grade is too high.\n";
            }
        };

    private:
        const std::string   _name;
        const int           _signGrade;
        const int           _execGrade;
        bool                _isSigned;

};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif