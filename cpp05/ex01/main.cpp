#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{

    std::cout << "################# TEST FROM EX00 #################" << std::endl;

    Bureaucrat validOne = Bureaucrat("James", 1);
    std::cout << "Valid bureaucrat: " << validOne << std::endl;

    std::cout << "Too high increment: ";
    try 
    {
        validOne.increment();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    Bureaucrat validTwo = Bureaucrat("Bobby", 150);
    std::cout << "Valid bureaucrat: " << validTwo << std::endl;
    
    std::cout << "Too low decrement: ";
    try 
    {
        validTwo.decrement();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Invalid bureaucrat: ";
    try 
    {
        Bureaucrat invalidOne = Bureaucrat("John", 151);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "################# FORM TESTS #################" << std::endl;

    Form validForm = Form("TestForm", 25, 10);
    std::cout << "Valid form: " << validForm << std::endl;

    std::cout << "Invalid form: ";
    try {
        Form invalidForm = Form("TestForm", 200, 10);
    }catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Invalid form 2: ";
    try {
        Form invalidForm = Form("TestForm", 0, 10);
    }catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "################# FORM SIGN TESTS #################" << std::endl;

    Form secretForm = Form("secretForm", 10, 1);

    Bureaucrat bad = Bureaucrat("Bad", 120);
    bad.signForm(secretForm);

    Bureaucrat god = Bureaucrat("God", 1);
    god.signForm(secretForm);

    return 0;
}