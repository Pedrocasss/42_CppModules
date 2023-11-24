#include "Zombie.hpp"

int main(void)
{
    int N = 7;
    Zombie *horde = zombieHorde(N, "Pedrocas");

    for (int i = 0; i < N; i++)
        horde[i].announce();
    delete[] horde;
}