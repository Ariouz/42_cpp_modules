#include "Bureaucrat.hpp"

int main(void)
{
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

    return 0;
}