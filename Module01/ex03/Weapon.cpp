#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->setType(type);
    //std::cout << "Weapon constructor here!" << std::endl;

}

Weapon::~Weapon(void)
{
    //std::cout << "Weapon destructor here!" << std::endl;
}

const std::string &Weapon::getType(void)
{
	return this->_type;
}

void    Weapon::setType(std::string type)
{
    this->_type = type;
}