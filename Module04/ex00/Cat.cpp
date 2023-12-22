#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Meow Constructor :p" << std::endl;
    setType("Cat");
}

Cat::Cat(Cat const &src): Animal(src)
{
    std::cout << "Meow Copy Constructor :p" << std::endl;
    *this = src;
}

Cat &Cat::operator=(Cat const &src) 
{
    type = src.getType();
    return *this;
}

Cat::~Cat()
{
    std::cout << "Meow Destructor :p" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "I am a cat. Meow" << std::endl;
}