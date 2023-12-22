#include "Dog.hpp"

Dog::Dog() : brain(new Brain) 
{
    std::cout << "Dog Constructor >.<" << std::endl;
    setType("Dog");
}

Dog::Dog(const Dog& src) : Animal(src), brain(new Brain(*src.brain)) 
{
    std::cout << "Woof Copy Constructor >.<" << std::endl;
}

Dog& Dog::operator=(const Dog& src) 
{
    if (this != &src) {
        setType(src.getType());
        delete brain;
        brain = new Brain(*src.brain);
    }
    return *this;
}

Dog::~Dog() 
{
    delete brain;
    std::cout << "Woof Destructor >.<" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "I am a dog. Woof woof!" << std::endl;
}