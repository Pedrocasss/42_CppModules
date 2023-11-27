#include "Harl.hpp"

Harl::Harl(void)
{
    //std::cout << "Constructor Harl here!" << std::endl;
    this->complainLevel[0] = "DEBUG";
    this->complainLevel[1] = "INFO";
    this->complainLevel[2] = "WARNING";
    this->complainLevel[3] = "ERROR";
}

Harl::~Harl(void)
{
    //std::cout << "Destructor Harl here!" << std::endl;
}

void Harl::complain(std::string level)
{
    int number = -1;
    while(++number < 4)
    {
        if(this->complainLevel[number] == level)
            break;
    }
    switch (number) 
    {
        case (0):
            this->debug();
            break ;
        case (1):
            this->info();
            break ;
        case (2):
            this->warning();
            break ;
        case (3):
            this->error();
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
    }

}

void    Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
    this->info();
}

void    Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
    this->warning();
}

void    Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
    this->error();
}

void    Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}
