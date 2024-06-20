#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    std::cout << "################# AForm EXECUTE TESTS #################" << std::endl;

    ShrubberyCreationForm shrubbery = ShrubberyCreationForm("Garden");

    Bureaucrat employee1 = Bureaucrat("Employee1", 148);
    std::cout << employee1 << std::endl;

    Bureaucrat employee2 = Bureaucrat("Employee2", 120);


    std::cout << "##### Shrubbery tests #####" << std::endl;

    try {
        employee1.signForm(shrubbery);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try {
        employee1.executeForm(shrubbery);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try {
        employee2.signForm(shrubbery);
    }

    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try {
        employee2.executeForm(shrubbery);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "##### Robotomy tests #####" << std::endl;

    RobotomyRequestForm robotomy = RobotomyRequestForm("Mario");

    std::cout << "## TEST ERRORS" << std::endl;

    try {
        employee1.signForm(robotomy);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try {
        employee1.executeForm(robotomy);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "## TEST SUCCESS" << std::endl;

    Bureaucrat employee3 = Bureaucrat("Employee3", 40);
    try {
        employee3.signForm(robotomy);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    try {
        employee3.executeForm(robotomy);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try {
        employee3.executeForm(robotomy);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "##### Presidential Pardon tests #####" << std::endl;

    PresidentialPardonForm pardonForm = PresidentialPardonForm("Luigi");

    std::cout << "## TEST ERRORS" << std::endl;

    try {
        employee3.signForm(pardonForm);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try {
        employee3.executeForm(pardonForm);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    Bureaucrat employee4 = Bureaucrat("Employee4", 2);

    try {
        employee4.signForm(pardonForm);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try {
        employee4.executeForm(pardonForm);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}