#include "Harl.hpp"

int main(int argc, char **argv)
{
    std::string string;
    Harl    Harl;
    
    if (argc == 2)
    {
        string = argv[1];
        Harl.complain(string);
    }
    else
        Harl.complain("");
    
}