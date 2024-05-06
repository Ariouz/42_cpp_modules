#include "Zombie.hpp"

int main(void)
{
    Zombie *bob = newZombie("Bob");
    bob->announce();

    randomChump("Harry");

    delete bob;

    return (0);
}