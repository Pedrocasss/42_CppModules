#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void    iter(T *array, int length, void(*function)(T const &element))
{
    for (int i = 0; i < length; i++)
        function(array[i]);
}

template <typename T>
void    print(T const &element)
{
    std::cout << element << std::endl;
}
#endif