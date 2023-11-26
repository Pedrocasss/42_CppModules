#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <cstdlib>

class Harl
{
    private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
    std::string complainLevel[4];
    public:
    void complain( std::string level );
    Harl(void);
    ~Harl(void);
};


#endif