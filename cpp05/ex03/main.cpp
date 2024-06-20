#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    std::cout << "################# Intern TESTS #################" << std::endl;

    Intern intern = Intern();
    Bureaucrat employee1 = Bureaucrat("Employee1", 1);

    AForm* form = intern.makeForm("shrubbery creation", "park");
    try {
        employee1.executeForm(*form);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}