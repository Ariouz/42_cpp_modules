#include "PhoneBook.hpp"

int main(void)
{
    bool running = true;
    std::string action;

    PhoneBook phone = PhoneBook();

    std::cout << "Welcome to PhoneBook !" << std::endl;

    while (running)
    {
        std::cout << "What do you want to do ? ADD, SEARCH, EXIT » ";
        std::cin >> action;

        if (action.compare("ADD") == 0)
            phone.add();
        else if (action.compare("SEARCH") == 0)
            phone.list();
        else if (action.compare("EXIT") == 0)
            running = false;
        else
            std::cout << "Invalid action, please retry ..." << std::endl;
    }

    std::cout << "GOODBYE !" << std::endl;
    return (0);
}