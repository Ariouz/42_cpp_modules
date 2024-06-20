#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        void    execute(const Bureaucrat& bureau) const;

    private:
        std::string _target;
};

#endif