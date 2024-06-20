#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class AForm
{

    public:
        AForm(const std::string& name, int signGrade, int execGrade);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        ~AForm();

        const std::string&  getName(void) const;
        bool                isSigned(void) const;
        int                 getExecGrade(void) const;
        int                 getSignGrade(void) const;

        void                beSigned(const Bureaucrat& bureau);
        virtual void        execute(const Bureaucrat& bureau) const = 0;

        class GradeTooLowException : public std::exception
        {
            const char* what() const throw()
            {
                return "AForm grade is too low.\n";
            }
        };

        class GradeTooHighException : public std::exception
        {
            const char* what() const throw()
            {
                return "AForm grade is too high.\n";
            }
        };

    private:
        const std::string   _name;
        const int           _signGrade;
        const int           _execGrade;
        bool                _isSigned;

};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#endif