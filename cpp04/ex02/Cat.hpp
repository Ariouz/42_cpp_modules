#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "AAnimal.hpp"

class Cat : public AAnimal
{
    public:
        Cat();
        ~Cat();

        void makeSound();

};

#endif