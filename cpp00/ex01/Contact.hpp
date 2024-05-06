#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>

class Contact
{

    public:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phone;
        std::string secret;

        Contact();
        Contact(const Contact& contact);
        Contact(std::string firstName, std::string lastName, std::string nickName, std::string phone, std::string secret);
        ~Contact();

        void create();
    
    private:
        std::string getContactField(std::string type);
};

#endif