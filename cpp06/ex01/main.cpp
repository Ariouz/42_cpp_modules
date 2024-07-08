# include "Serializer.hpp"
# include <iostream>

int main(void)
{
    Data data;
    data.value = 42;
    std::cout << "Data value: " << data.value << std::endl;

    uintptr_t ptr = Serializer::serialize(&data);
    std::cout << "Ptr value: " << ptr << std::endl;

    Data *res = Serializer::deserialize(ptr);

    std::cout << "Deserialized Data value: " << res->value << std::endl;

    return 0;
}