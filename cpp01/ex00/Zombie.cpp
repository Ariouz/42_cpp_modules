#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name){}

Zombie::Zombie(){}

Zombie::Zombie(Zombie& zombie)
{
    this->name = zombie.name;
}

Zombie::~Zombie(){
    std::cout << "Destroyed " << this->name << std::endl;
}

void Zombie::announce()
{
    std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}