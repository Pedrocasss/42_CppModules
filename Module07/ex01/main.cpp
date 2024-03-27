#include "iter.hpp"

int main(void)
{
    int int_array[] = {1, 2, 3, 4, 5};
    char char_array[] = {'a', 'b', 'c', 'd', 'e'};
    std::string string_array[] = {"one", "two", "three", "four", "five"};

    std::cout << "Int array:" << std::endl;
    ::iter(int_array, 5, print <const int>);
    std::cout << "Char array:" << std::endl;
    ::iter(char_array, 5, print <char>);
    std::cout << "String array:" << std::endl;
    ::iter(string_array, 5, print <std::string>);
    //std::cout << "Does not work:" << std::endl;
    //::iter(int_array, 5, print <char>);
    return 0;
}