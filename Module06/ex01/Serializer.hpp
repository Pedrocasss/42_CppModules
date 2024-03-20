#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <ctime>
#include "Data.hpp"
#include <stdint.h>

class Serializer
{
    private:
        Serializer();
        Serializer(Serializer const & src);
        Serializer & operator=(Serializer const & src);

    public:
        ~Serializer();
        static uintptr_t	serialize(Data* raw);
	    static Data*		deserialize(uintptr_t ptr);
};




#endif