#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook(){}

PhoneBook& PhoneBook::operator=(const PhoneBook& other)
{
    if (this == &other)
        return *this;
    for (int i = 0; i < getContactsLen(); i++)
        this->contacts[i] = other.contacts[i];
    return *this;
}

PhoneBook::PhoneBook(const PhoneBook& p){
    for (int i = 0; i < getContactsLen(); i++)
        this->contacts[i] = p.contacts[i];
}

PhoneBook::~PhoneBook(){}

void PhoneBook::add()
{
    static int index;

    this->contacts[index % 8].create();
    std::cout << "Contact added to your PhoneBook !" << std::endl;
    std::cin.clear();
    index++;
}

void PhoneBook::show(int index)
{
    if (index < 0 || index >= 8)
    {
        std::cout << "Invalid index" << std::endl;
        return ;
    }

    Contact contact = this->contacts[index];

    std::cout << "Index: " << index << std::endl;
    std::cout << "FirstName: " << contact.firstName << std::endl;
    std::cout << "LastName: " << contact.lastName << std::endl;
    std::cout << "NickName: " << contact.nickName << std::endl;
    std::cout << "Phone: " << contact.phone << std::endl;
    std::cout << "Secret: " << contact.secret << std::endl;
}

void PhoneBook::list()
{

    if (this->contacts[0].firstName[0] == 0)
    {
        std::cout << "You don't have any contact!" << std::endl;
        return ;
    }

    std::cout << std::right << std::setw(10) << truncate("Index");
    std::cout << "|" << std::right << std::setw(10) << truncate("FirstName");
    std::cout << "|" << std::right << std::setw(10) << truncate("LastName");
    std::cout << "|" << std::right << std::setw(10) << truncate("NickName");
    std::cout << std::endl;
    for (int index = 0; index < 8; index++)
    {
        Contact contact = this->contacts[index];

        if (contact.firstName[0] == 0)
            break;
        std::cout << std::right << std::setw(10) << index;
        std::cout << "|" << std::right << std::setw(10) << truncate(contact.firstName);
        std::cout << "|" << std::right << std::setw(10) << truncate(contact.lastName);
        std::cout << "|" << std::right << std::setw(10) << truncate(contact.nickName);
        std::cout << std::endl;
    }

    int index;
    std::cout << "Enter the contact's index you would like to get the information: ";
    while (!(std::cin >> index))
    {
        std::cout << "Please, enter a valid index: ";
        std::cin.clear();
        std::cin.ignore();
    }
    show(index);
}

std::string PhoneBook::truncate(std::string field)
{
    if (field.size() > 10)
        return field.substr(0, 9) + ".";
    return (field);
}

int PhoneBook::getContactsLen()
{
    return (int) (sizeof(this->contacts) / sizeof(Contact));
}
