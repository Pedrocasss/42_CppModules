#include "Zombie.hpp"

Zombie::Zombie( std::string name) : _name(name)
{
    std::cout << "Zombie " << this->_name << " constructor here" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie " << this->_name << " destructor here" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}