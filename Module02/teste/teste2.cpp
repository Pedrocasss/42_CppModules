/*Operator Overload:

Operator overloading lets you define custom behaviors for operators when used with user-defined classes.
Here's an example using the + operator:*/

#include "teste2.hpp"

void    Complex::display()
{
    std::cout << real << " + " << imaginary <<"i" << std::endl;
}

int main(void)
{
    Complex c1(3.1, 1.5);
    Complex c2(2.0, 1.0);

    Complex sum = c1 + c2;

    sum.display();
    return 0;
}

