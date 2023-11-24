#include "Zombie.hpp"

Zombie::Zombie(void)
{
    std::cout <<"Constructor here"<<std::endl;
}

Zombie::~Zombie(void) 
{
    std::cout<<"Destructor here: " << this->_name << " was deleted\n";
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name)
{
    this->_name = name;
}