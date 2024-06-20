#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Form;

class Bureaucrat
{
    public:
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        const std::string& getName(void) const;
        int getGrade(void) const;

        void    increment(void);
        void    decrement(void);

        void    signForm(Form& form) const;

        class GradeTooLowException : public std::exception
        {
            const char* what() const throw()
            {
                return "Bureaucrat grade is too low.\n";
            }
        };

        class GradeTooHighException : public std::exception
        {
            const char* what() const throw()
            {
                return "Bureaucrat grade is too high.\n";
            }
        };

    private:
        const std::string   _name;
        int                 _grade;

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureau);

#endif