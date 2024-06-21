#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>

#include "AForm.hpp"

class Intern
{
    public:
        Intern();
        Intern& operator=(const Intern& other);
        Intern(const Intern& other);
        ~Intern();

        static AForm*       makeShrubberyForm(const std::string& target);
        static AForm*       makePresidentialPardon(const std::string& target);
        static AForm*       makeRobotomy(const std::string& target);
         

        AForm*    makeForm(const std::string& formName, const std::string& target);
};

# endif