#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "Not a cat Constructor :p" << std::endl;
    setType("WrongCat");
}

WrongCat::WrongCat(WrongCat const &src): WrongAnimal(src)
{
    std::cout << "Not a cat Copy Constructor :p" << std::endl;
    *this = src;
}

WrongCat &WrongCat::operator=(WrongCat const &src) 
{
    type = src.getType();
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "Not a cat Destructor :p" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "I am not a cat MUAHAHAHAHAHA." << std::endl;
}
