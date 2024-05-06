#include "Harl.hpp"

Harl::Harl(){
    this->functions["debug"] = &Harl::debug;
    this->functions["info"] = &Harl::info;
    this->functions["warning"] = &Harl::warning;
    this->functions["error"] = &Harl::error;
}

Harl::~Harl(){};

void Harl::complain(std::string level)
{
    if (this->functions.find(level) != this->functions.end())
        (this->*functions[level])();
    else
        std::cout << "Unknown level" << std::endl;
}

void Harl::debug()
{
    std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
    std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
    std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}