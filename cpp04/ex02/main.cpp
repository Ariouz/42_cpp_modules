#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    int size = 4;
    AAnimal* animals[size];
    for (int i = 0; i < size; i++)
    {
        if (i > size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
        std::cout << "--------" << std::endl;
    }

    animals[0]->getBrain()->getIdeas()[0] = "Fish";
    animals[0]->makeSound();
    animals[2]->makeSound();

    Brain *catBrain = animals[0]->getBrain();
    std::cout << "Cat's first idea is " << catBrain->getIdeas()[0] << std::endl;
    
    for (int i = 0; i < size; i++)
        delete animals[i];


    return (0);
}