#ifndef FIXED_HPP
# define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
    private:
    int number;
    static const int fracBits = 8;
    public:
    Fixed (void);
    Fixed(Fixed const & copy);
    Fixed (const int value);
    Fixed (const float value);
    ~Fixed(void);

    int getRawBits( void ) const;
    void setRawBits( int const raw );
    Fixed &operator=(const Fixed &other);
};




#endif