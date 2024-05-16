#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    public:
        Contact contacts[8];

        PhoneBook();
        PhoneBook& operator=(const PhoneBook& other);
        PhoneBook(const PhoneBook& p);
        ~PhoneBook();

        void list();
        void show(int index);
        void add();
    
    private:
        int getContactsLen();
        std::string truncate(std::string field);
};

#endif