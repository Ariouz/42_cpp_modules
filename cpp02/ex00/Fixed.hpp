#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed& fixed);
        ~Fixed();
        Fixed& operator=(const Fixed& fixed);
    
        int getRawBits() const;
        void setRawBits(const int raw);

    private:
        int value;
        static const int bits = 8;
};

#endif