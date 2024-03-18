#include <iostream>

int main(int argc, char **argv)
{
    int number1 = 9;

    double number2 = number1;
    std::cout << "      ---------------Implicit and Explicit type cast---------------\n\n";
    std::cout << "----------TEST ONE----------\n";
    std::cout << "Integer value : " << number1 << std::endl;
    std::cout << "Double value : " << number2 << std::endl;

    std::cout << "----------TEST TWO----------\n";
    int number4;
    double number5 = 9.76;
    number4 = number5;

    std::cout << "Integer value : " << number4 << std::endl;
    std::cout << "Double value : " << number5 << std::endl;

    std::cout << "----------TEST THREE----------\n";

    int number3 = 48;
    char test = number3;
    std::cout << "Integer value : " << number3 << std::endl;
    std::cout << "Char value : " << test << std::endl;

    std::cout << "----------TEST FOUR----------\n";

    int num1 = 10, num2 = 4;

    float res;

    std::cout << "This is a implicit conversion\n";
    std::cout << "Result : " << num1 / num2 << std::endl;
    std::cout << "---------------------------------" << std::endl;
    std::cout << "This is a explicit conversion\n";
    res = (float) num1/num2;
    std::cout << "Result : " << res << std::endl;
    std::cout << "\n\n\n";
    std::cout << "      ---------------Static cast---------------\n\n";
    //std::cout << ""
}