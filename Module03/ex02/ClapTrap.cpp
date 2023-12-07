#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :  hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "Constructor ClapTrap here!" << std::endl;
}

ClapTrap::ClapTrap(const std::string newName) : _name(newName), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "Constructor ClapTrap here for " << _name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& src)
{
    *this = src;
    std::cout << "Copy constructor ClapTrap here!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap&  other)
{
    std::cout << "Claptrap Assignation operator here!" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor ClapTrap here for " << _name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	this->energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	hitPoints -= amount;
	if(hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " is repaired " << amount << " points of damage!" << std::endl;
	hitPoints += amount;
	this->energyPoints -= 1;
}

int ClapTrap::getHP()
{
    return this->hitPoints;
}

int ClapTrap::getEnergy()
{
    //std::cout << "ClapTrap " << _name << " has " << energyPoints << " energy points!" << std::endl;
	return this->energyPoints;
}

int ClapTrap::getAttackDamage()
{
    return this->attackDamage;
}

void ClapTrap::setAttackDamage(int amount)
{
	this->attackDamage = amount;
}

void ClapTrap::setHP(int amount)
{
	this->hitPoints = amount;
}

void ClapTrap::setEnergy(int amount)
{
	this->energyPoints = amount;
}