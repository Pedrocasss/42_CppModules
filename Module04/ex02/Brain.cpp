#include "Brain.hpp"

Brain::Brain() : ideas()
{
    std::cout << "Brain constructor here, yes im a brain." << std::endl;
}

Brain::Brain(Brain const &src)
{
    std::cout << "Brain copy constructor here, yes im a brain."  << std::endl;
    for (int i = 0; i < 100; ++i) {
        this->ideas[i] = src.ideas[i];
    }
}

Brain &Brain::operator=(Brain const &src) 
{
    
   if (this != &src) 
   {
        std::cout << "Brain operator= here, yes im a brain." << std::endl;
        for (int i = 0; i < 100; ++i) 
        {
            this->ideas[i] = src.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor here, now im not a brain because im dead" << std::endl;
}
