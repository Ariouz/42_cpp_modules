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

Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string phone, std::string secret) :
firstName(firstName), lastName(lastName), nickName(nickName), phone(phone), secret(secret) {}

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