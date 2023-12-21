#pragma once
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public virtual FragTrap, public virtual ScavTrap
{
private:
    std::string _name;

public:
    const std::string &getName() const;
    DiamondTrap();
    DiamondTrap(const std::string &name);
    DiamondTrap(const DiamondTrap &src);
    DiamondTrap &operator=(DiamondTrap const &src);
    ~DiamondTrap();

    virtual void attack(const std::string &);
    void whoAmI();
};

#endif
