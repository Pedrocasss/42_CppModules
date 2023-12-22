#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog Constructor >.<" << std::endl;
    setType("Dog");
}

Dog::Dog(Dog const &src): Animal(src)
{
    std::cout << "Woof Copy Constructor >.<" << std::endl;
    *this = src;
}

Dog &Dog::operator=(Dog const &src) 
{
    type = src.getType();
    return *this;
}

Dog::~Dog()
{
    std::cout << "Woof Destructor >.<" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "I am a dog. Woof woof!" << std::endl;
}