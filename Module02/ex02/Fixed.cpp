#include "Fixed.hpp"

Fixed::Fixed(void) : number(0)
{
    std::cout << "Constructor Fixed here!" << std::endl;
}

Fixed::Fixed(Fixed const & copy)
{
    std::cout << "Copy constructor here!" << std::endl;
    *this = copy;
}

Fixed::Fixed(const int value)
{
    std::cout << "Constructor Int Fixed here!" << std::endl;
    this->setRawBits(value << fracBits);
}

Fixed::Fixed(const float value)
{
    std::cout << "Constructor Float Fixed here!" << std::endl;
    this->setRawBits(roundf(value * (1 << fracBits)));
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor Fixed here!" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return number;
}

void Fixed::setRawBits(int const raw)
{
    this->number = raw;
}

Fixed &Fixed::operator=(const Fixed &other) 
{
    std::cout << "Copy assignment operator Fixed here!" << std::endl;
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return *this;
}

