#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
    std::cout << "Constructor AAnimal here!" << std::endl;
}

AAnimal::AAnimal(AAnimal const &src)
{
    *this = src;
    std::cout << "Copy constructor AAnimal here!" << std::endl;
}

AAnimal &AAnimal::operator=(AAnimal const &src) 
{
    type = src.getType();
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "Destructor AAnimal here!" << std::endl;
}

void    AAnimal::setType(const std::string& newType)
{
    type = newType;
}

std::string	AAnimal::getType() const
{
	return type;
}

/*A função makeSound é declarada como virtual porque ela será sobrescrita por classes derivadas (cat, dog...). 
Quando uma função é declarada como virtual, isso significa que as classes derivadas podem fornecer uma implementação específica 
para essa função, substituindo a implementação da classe base.

No contexto do polimorfismo em C++, a utilização de funções virtuais permite que chamadas de método sejam resolvidas dinamicamente 
em tempo de execução, o que é essencial para o funcionamento correto do polimorfismo.*/

void    AAnimal::makeSound() const 
{
    std::cout << "Generic AAnimal sound" << std::endl;
}

