#include "Zombie.hpp"

/*
Usamos o delete para apagar a nossa alocacao na heap (new)
*/
int main() 
{
    randomChump("Pedro");
    Zombie *d = newZombie("Diogo");
    d->announce();
    delete d;
    return 0;
}