#include "Cat.hpp"

Cat::Cat() : brain(new Brain)
{
    std::cout << "Meow Constructor :p" << std::endl;
    setType("Cat");
}

Cat::Cat(Cat const &src): Animal(src), brain(new Brain(*src.brain))
{
    std::cout << "Meow Copy Constructor :p" << std::endl;
}

Cat &Cat::operator=(Cat const &src) 
{
    if (this != &src) {
        setType(src.getType());
        delete brain;
        brain = new Brain(*src.brain);
    }
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Meow Destructor :p" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "I am a cat. Meow" << std::endl;
}
