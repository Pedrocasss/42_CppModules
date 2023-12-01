#include "Fixed.hpp"

Fixed::Fixed(void) : number(0)
{
    //std::cout << "Constructor Fixed here!" << std::endl;
}

Fixed::Fixed(Fixed const & copy)
{
    //std::cout << "Copy constructor here!" << std::endl;
    *this = copy;
}

Fixed::Fixed(const int value)
{
    //std::cout << "Constructor Int Fixed here!" << std::endl;
    this->setRawBits(value << fracBits);
}

Fixed::Fixed(const float value)
{
    //std::cout << "Constructor Float Fixed here!" << std::endl;
    this->setRawBits(roundf(value * (1 << fracBits)));
}

Fixed::~Fixed(void)
{
    //std::cout << "Destructor Fixed here!" << std::endl;
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
   // std::cout << "Copy assignment operator Fixed here!" << std::endl;
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return *this;
}

float		Fixed::toFloat(void) const
{
	return (float)this->getRawBits() / (1 << fracBits);
}

int		Fixed::toInt ( void ) const
{
	return this->getRawBits() >> fracBits;
}

std::ostream &	operator<<(std::ostream & out, Fixed const & number)
{
	out << number.toFloat();
	return out;
}

bool Fixed::operator<(const Fixed &fixed) const 
{ 
    return this->number < fixed.getRawBits(); 
}

bool Fixed::operator>(const Fixed &fixed) const 
{ 
    return this->number > fixed.getRawBits(); 
}

bool Fixed::operator==(const Fixed &fixed) const 
{ 
    return this->number == fixed.getRawBits(); 
}

bool Fixed::operator!=(const Fixed &fixed) const 
{ 
    return this->number != fixed.getRawBits(); 
}

bool Fixed::operator<=(const Fixed &fixed) const 
{ 
    return this->number <= fixed.getRawBits(); 
}

bool Fixed::operator>=(const Fixed &fixed) const 
{
     return this->number >= fixed.getRawBits(); 
}

Fixed Fixed::operator+(const Fixed &fixed) const 
{ 
    return this->toFloat() + fixed.toFloat(); 
}

Fixed Fixed::operator-(const Fixed &fixed) const 
{ 
    return this->toFloat() - fixed.toFloat(); 
}

Fixed Fixed::operator*(const Fixed &fixed) const 
{ 
    return this->toFloat() * fixed.toFloat(); 
}

Fixed Fixed::operator/(const Fixed &fixed) const 
{ 
    return this->toFloat() / fixed.toFloat(); 
}

Fixed &Fixed::operator++(void)
{
	this->number++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->number++;
	return tmp;
}

Fixed &Fixed::operator--(void)
{
	this->number--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->number--;
	return tmp;
}

Fixed &Fixed::min(Fixed &number1, Fixed &number2)
{
	if (number1.getRawBits() < number2.getRawBits())
		return number1;
	return number2;
}

const Fixed &Fixed::min(const Fixed &number1, const Fixed &number2)
{
	if (number1.getRawBits() < number2.getRawBits())
		return number1;
	return number2;
}

Fixed &Fixed::max(Fixed &number1, Fixed &number2)
{
	if (number1.getRawBits() > number2.getRawBits())
		return number1;
	return number2;
}

const Fixed &Fixed::max(const Fixed &number1, const Fixed &number2)
{
	if (number1.getRawBits() > number2.getRawBits())
		return number1;
	return number2;
}