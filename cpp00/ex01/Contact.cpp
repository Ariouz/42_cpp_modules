#include "Contact.hpp"

Contact::Contact(){}

Contact::Contact(const Contact& contact)
{
    this->firstName = contact.firstName;
    this->lastName = contact.lastName;
    this->nickName = contact.lastName;
    this->phone = contact.phone;
    this->secret = contact.phone;
}

Contact& Contact::operator=(const Contact& other)
{
    if (this == &other)
        return *this;
    this->firstName = other.firstName;
    this->lastName = other.lastName;
    this->nickName = other.nickName;
    this->phone = other.phone;
    this->secret = other.secret;
    return *this;
}

Contact::~Contact() {}

void Contact::create()
{
    this->firstName = getContactField("firstname");
    this->lastName = getContactField("lastname");
    this->nickName = getContactField("nickname");
    this->phone = getContactField("phone");
    this->secret = getContactField("secret");
    std::cin.clear();
}

std::string Contact::getContactField(std::string type)
{
    std::string val;

    std::cout << "Contact's "<< type <<": ";
    std::cin >> val;
    return (val);
}