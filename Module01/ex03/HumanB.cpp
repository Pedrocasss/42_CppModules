#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    //std::cout << "HumanB constructor here!" << std::endl;
    this->_name = name;
    this->_weapon = NULL;
}

HumanB::~HumanB(void)
{
    //std::cout << "HumanB destructor here!" << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}

void    HumanB::attack(void)
{
    if (!this->_weapon)
        std::cout << this->_name << " Not armed, let's do some punches!" << std::endl;
    else
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
