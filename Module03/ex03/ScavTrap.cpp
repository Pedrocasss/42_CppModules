#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "Constructor ScavTrap here!" << std::endl;
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
    std::cout << "Constructor Scavtrap " << _name << " here!" << std::endl;
    setAttackDamage(20);
    setEnergy(50);
    setHP(100);
    //displayStats();
}

void ScavTrap::displayStats()
{
    std::cout << "Name: " << _name << std::endl;
	std::cout << "Hit Points: " << hitPoints << std::endl;
	std::cout << "Energy Points: " << energyPoints << std::endl;
	std::cout << "Attack Damage: " << attackDamage << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap("ScavTrap")
{
    std::cout << "Copy constructor ScavTrap here!" << std::endl;
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap Assignation operator here!" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor ScavTrap here for " << _name << std::endl;;
}

void ScavTrap::attack(std::string const& target)
{
	if (getHP() && getEnergy())
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		this->energyPoints -= 1;
	}
	else if (!getHP())
		std::cout << "ScavTrap " << _name << " is dead and can't attack " << target << "." << std::endl;
	 else
		std::cout << "ScavTrap " << _name << " doesn't have enough energyPoints to attack." << std::endl; 
}	

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode." << std::endl;
}