#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "Constructor WrongAnimal here! But im not human ok." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
    *this = src;
    std::cout << "Copy constructor WrongAnimal here!" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &src) 
{
    type = src.getType();
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destructor WrongAnimal here! Again im not human..." << std::endl;
}

void    WrongAnimal::setType(const std::string& newType)
{
    type = newType;
}

std::string	WrongAnimal::getType() const
{
	return type;
}

void    WrongAnimal::makeSound() const 
{
    std::cout << "Generic animal sou...ops Generic wrong sound hehehehe" << std::endl;
}