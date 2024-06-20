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

        AForm*    makeForm(const std::string& formName, const std::string& target);
};

# endif