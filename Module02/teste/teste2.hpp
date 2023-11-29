/*Operator Overload:

Operator overloading lets you define custom behaviors for operators when used with user-defined classes.
Here's an example using the + operator:*/

#ifndef TESTE2_HPP
# define TESTE2_HPP

#include <iostream>

class Complex{
    private:
    double real;
    double imaginary;

    public:
    Complex(double r, double i) : real(r), imaginary(i) {}

    Complex operator+(const Complex& copy) {
        return Complex(real + copy.real, imaginary + copy.imaginary);
    }
    void display();
};


#endif