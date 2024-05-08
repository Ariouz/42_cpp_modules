#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
    public:
        AAnimal();
        virtual ~AAnimal();
    
        std::string getType() const;
        Brain *getBrain() const;
        virtual void makeSound() = 0;
    protected:
        std::string type;
        Brain* brain;
};

#endif