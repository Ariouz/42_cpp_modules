#ifndef SCALAR_CONVERTER
# define SCALAR_CONVERTER

# include <iostream>
# include <string>
# include <stdlib.h>

class ScalarConverter
{
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

        void    convert(const std::string& value) const;
};

#endif