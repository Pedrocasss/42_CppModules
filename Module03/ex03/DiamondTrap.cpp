#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): FragTrap(), ScavTrap() {
    std::cout << "DiamondTrap created!" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_name") ,FragTrap(name), ScavTrap(name), _name(name)
{
    std::cout << "Constructor DiamondTrap here!" << std::endl;
    FragTrap::hitPoints = 100;
    FragTrap::attackDamage = 30;
    energyPoints = ScavTrap::energyPoints;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src): ClapTrap(), FragTrap(), ScavTrap() 
{
    std::cout << "Copy constructor DiamondTrap here!" << std::endl;
    *this = src;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &src) 
{
    this->_name = src._name;
    this->hitPoints = src.hitPoints;
    this->attackDamage = src.attackDamage;
    this->energyPoints = src.energyPoints;
    return *this;
}

DiamondTrap::~DiamondTrap() 
{
    std::cout << "Destructor DiamondTrap here for " << _name << std::endl;
}

void DiamondTrap::attack(const std::string &n) 
{
    ScavTrap::attack(n);
}

void DiamondTrap::whoAmI() 
{
    std::cout << "My name is: " << _name << " and my ClapTrap name is: " << ClapTrap::_name << std::endl;
}

const std::string &DiamondTrap::getName() const {
    return _name;
}
