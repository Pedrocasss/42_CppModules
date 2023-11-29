/*Ad-hoc Polymorphism

Ad-hoc polymorphism allows a function to behave differently based on the types of arguments it receives.
This is achieved through function overloading. 
Here's an example:*/

#include <iostream>

int add(int a, int b)
{
    return a + b;
}

double add(double a, double b)
{
    return a + b;
}

int main(void)
{
    int sumInt = add(10, 3);
    double sumDouble = add(10.56, 2.364);

    std::cout << "Sum with integers: " << sumInt << std::endl;
    std::cout << "Sum with doubles: " << sumDouble << std::endl;

    return 0;
}