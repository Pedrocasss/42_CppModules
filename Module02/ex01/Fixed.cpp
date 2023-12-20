#include "Fixed.hpp"

Fixed::Fixed() : number(0)
{
    std::cout <<"Default constructor called" << std::endl;
}


Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->setRawBits(value << fracBits);
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->setRawBits(roundf(value * (1 << fracBits)));
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return *this;
}

int Fixed::getRawBits(void) const
{
    return number;
}

void Fixed::setRawBits(int const raw)
{
    this->number = raw;
}

float		Fixed::toFloat(void) const
{
	return (float)this->getRawBits() / (1 << fracBits);
}

int		Fixed::toInt ( void ) const
{
	return this->getRawBits() >> fracBits;
}

//overload operator
std::ostream &	operator<<(std::ostream & out, Fixed const & number)
{
	out << number.toFloat();
	return out;
}
