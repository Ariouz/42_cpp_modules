#ifndef HUMAN_A_H
# define HUMAN_A_H

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{

    public:
        HumanA(std::string name, Weapon& weapon);
        HumanA(const HumanA& human);
        ~HumanA();

        void attack();

    private:
        std::string name;
        Weapon& weapon;

};

#endif
