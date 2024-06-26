#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){}

Intern& Intern::operator=(const Intern& other) {(void) other; return *this;}

Intern::Intern(const Intern& other) {(void) other;}

Intern::~Intern() {}

AForm* Intern::makeShrubberyForm(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makePresidentialPardon(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm*  Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string names[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    AForm* (*forms[])(const std::string&) = {makeRobotomy, makePresidentialPardon, makeShrubberyForm};

    for (std::size_t index = 0; index < 3; index++)
    {
        if (names[index].compare(formName) == 0)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[index](target);
        }
    }
    std::cout << "Intern cannot create " << formName << " because it doesn't exist." << std::endl;
    return NULL;
}