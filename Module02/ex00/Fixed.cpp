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
    this->setRawBits(copy.getRawBits());
}
Fixed &Fixed::operator=(const Fixed &other) 
{
    std::cout << "Copy assignment operator Fixed here!" << std::endl;
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return *this;
}
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->number;
}

void Fixed::setRawBits(int const raw)
{
    this->number = raw;
}