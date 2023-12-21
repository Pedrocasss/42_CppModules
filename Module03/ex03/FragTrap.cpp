#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "Constructor FragTrap here!" << std::endl;
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
    std::cout << "Constructor FragTrap " << _name << " here!" << std::endl;
    setAttackDamage(30);
    setEnergy(100);
    setHP(100);
    //displayStats();
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap("FragTrap")
{
    std::cout << "Copy constructor FragTrap here!" << std::endl;
    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap Assignation operator here!" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor FragTrap here for " << _name << std::endl;;
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << _name << " wants to high five you! :)" << std::endl;
}
void FragTrap::displayStats()
{
    std::cout << "Name: " << _name << std::endl;
	std::cout << "Hit Points: " << hitPoints << std::endl;
	std::cout << "Energy Points: " << energyPoints << std::endl;
	std::cout << "Attack Damage: " << attackDamage << std::endl;
}

