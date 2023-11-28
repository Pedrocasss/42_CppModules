#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Constructor Fixed here!" << std::endl;
    this->number = 0;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor Fixed here!" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor Fixed here!" << std::endl;
}

