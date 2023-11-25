#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _weapon(weapon)
{
    //std::cout << "HumanA constructor here!" << std::endl;
    this->_name = name;
}

HumanA::~HumanA(void)
{
    //std::cout << "HumanA destructor here!" << std::endl;
}

void    HumanA::attack(void)
{
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}