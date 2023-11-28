#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
    int number;
    static const int bits = 8;
    public:
    Fixed();    //constructor
    ~Fixed();   //destructor
    Fixed(const Fixed &copy); //copy constructor
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};





#endif