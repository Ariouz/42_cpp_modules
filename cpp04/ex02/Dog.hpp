#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"

class Dog : public AAnimal
{
    public:
        Dog();
        ~Dog();

        void makeSound();

};

#endif