# include "Base.hpp"
# include <iostream>
# include <cstdlib>
# include <ctime>

Base *generate(void)
{
    std::srand(std::time(0)) ;
    int random = std::rand() % 3;
    std::cout << "Random class generated: ";
    Base *gen;
    switch (random)
    {
        case 0:
            gen = new A();
            std::cout << "A";
            break;
        case 1:
            gen = new B();
            std::cout << "B";
            break;
        case 2:
            gen = new C();
            std::cout << "C";
            break;
    }
    std::cout << std::endl;
    return gen;
}

void identify(Base *p)
{
    if (p == 0)
    {
        std::cout << "Base type is NULL" << std::endl;
        return ;
    }

    if (dynamic_cast<A *>(p) != NULL)
        std::cout << "Base type is A" << std::endl;
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout << "Base type is B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "Base type is C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void) dynamic_cast<A&>(p);
        std::cout << "Base ref type is A" << std::endl;
        return; 
    } catch (std::exception &e) {}

    try
    {
        (void) dynamic_cast<B&>(p);
        std::cout << "Base ref type is B" << std::endl;
        return; 
    } catch (std::exception &e) {}

    try
    {
        (void) dynamic_cast<C&>(p);
        std::cout << "Base ref type is C" << std::endl;
        return; 
    } catch (std::exception &e) {}
    std::cout << "Base ref type is NUll" << std::endl;
}

int main(void)
{
    Base *random = generate();
    
    identify(random);
    identify(*random);
    return 0;
}