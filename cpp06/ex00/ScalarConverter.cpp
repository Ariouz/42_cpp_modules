# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {(void) other;}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {(void) other; return *this;}
ScalarConverter::~ScalarConverter() {}

static void convertInt(int n)
{
    std::cout << "char: " << (std::isprint((char) n) ? ((char) n + "" ): "Non displayable") << std::endl;
    std::cout << "int: " << n << std::endl;
}

static void convertFloat(float n)
{
    std::cout << "char: " << (std::isprint((char) n) ? ((char) n + "" ): "Non displayable") << std::endl;
    std::cout << "int: " << n << std::endl;


}

static void convertDouble(float n)
{
    std::cout << "char: " << (std::isprint((char) n) ? ((char) n + "" ): "Non displayable") << std::endl;
    std::cout << "int: " << n << std::endl;


}

static void convertChar(char c)
{
    std::cout << "char: " << (std::isprint(c) ? (c + "" ): "Non displayable") << std::endl;
    std::cout << "int: " << (int)c << std::endl;


}

void ScalarConverter::convert(const std::string& value) const
{

    try
    {
        int num = static_cast<int> (atoi(value.c_str()));
        convertInt(num);
        return ;
    } catch (std::exception &e) {}

    try
    {
        float num = static_cast<float> (atof(value.c_str()));
        convertFloat(num);
        return ;
    } catch (std::exception &e) {}
    
    try
    {
        double num = static_cast<double> (atof(value.c_str()));
        convertDouble(num);
        return ;
    } catch (std::exception &e) {}

    try
    {
        char c = static_cast<char> (value[0]);
        convertChar(c);
        return ;
    } catch (std::exception &e) {}

}