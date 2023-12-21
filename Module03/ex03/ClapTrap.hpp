#pragma once

#ifndef CLAPTRAP_HPP
 #define CLAPTRAP_HPP


#include <iostream>
class ClapTrap
{
    protected:
        std::string _name;
        int hitPoints;
        int energyPoints;
        int attackDamage;
    public:
        ClapTrap();
        ClapTrap(ClapTrap const & src);
        ClapTrap(const std::string newName);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        int getHP();
        int getEnergy();
        int getAttackDamage();
        void setAttackDamage(int attackDamage);
		void setHP(int health);
		void setEnergy(int energy);
};

#endif