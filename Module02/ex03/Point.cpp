#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
    //std::cout << "Constructor Point here!" << std::endl;
}

Point::Point(const float x, const float y) :  _x(x), _y(y)
{
    //std::cout << "Constructor with const floats here!" << std::endl;
}

Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
    //std::cout << "Copy constructor Point here!" << std::endl;
}

Point &	Point::operator=(Point const &other)
{
	(Fixed &)this->_x = other._x;
	(Fixed &)this->_y = other._y;
	return *this;
}
Point::~Point()
{
    //std::cout << "Destructor Point here!" << std::endl;
}

Fixed Point::getX() const 
{
    return (this->_x.toFloat());
}

Fixed Point::getY() const 
{
   return (this->_y.toFloat());
}


