#include "Serializer.hpp"

int main()
{
    // Create a Data object
    Data data;
    data.n = 42;
    data.str = "Pedrocas, o rei!";
    data.d = 3.14;

    std::cout << "Original Data:\n";
    std::cout << "n: " << data.n << "\nstr: " << data.str << "\nd: " << data.d << "\n\n";
    uintptr_t raw = Serializer::serialize(&data);
    Data *ptr = Serializer::deserialize(raw);

    std::cout << "Deserialized Data:\n";
    std::cout << "n: " << ptr->n << "\nstr: " << ptr->str << "\nd: " << ptr->d << "\n\n";

    if (ptr->n == data.n && ptr->str == data.str && ptr->d == data.d)
        std::cout << "Serialization and deserialization were successful!" << std::endl;
    else
        std::cout << "Serialization and deserialization failed!" << std::endl;

    return 0;
}