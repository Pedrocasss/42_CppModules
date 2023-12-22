#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Constructor Animal here!" << std::endl;
}

Animal::Animal(Animal const &src)
{
    *this = src;
    std::cout << "Copy constructor Animal here!" << std::endl;
}

Animal &Animal::operator=(Animal const &src) 
{
    type = src.getType();
    return *this;
}

Animal::~Animal()
{
    std::cout << "Destructor Animal here!" << std::endl;
}

void    Animal::setType(const std::string& newType)
{
    type = newType;
}

std::string	Animal::getType() const
{
	return type;
}

/*A função makeSound é declarada como virtual porque ela será sobrescrita por classes derivadas (cat, dog...). 
Quando uma função é declarada como virtual, isso significa que as classes derivadas podem fornecer uma implementação específica 
para essa função, substituindo a implementação da classe base.

No contexto do polimorfismo em C++, a utilização de funções virtuais permite que chamadas de método sejam resolvidas dinamicamente 
em tempo de execução, o que é essencial para o funcionamento correto do polimorfismo.*/

void    Animal::makeSound() const 
{
    std::cout << "Generic animal sound" << std::endl;
}