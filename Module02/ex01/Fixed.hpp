#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
    int number;
    static const int fracBits = 8;

    public:
    Fixed(const int value);
    Fixed(const float value);
    float toFloat( void ) const;
    int toInt( void ) const;
    
};




#endif