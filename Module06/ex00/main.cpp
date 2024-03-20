#include "ScalarConverter.hpp"

/*
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
    std::cout << "      ---------------Static cast---------------\n";
    std::cout << "Capable enough that can perfome all the conversions carried out by the implicit cast\n";
    std::cout << "Compile time casting\n";
    std::cout << "Syntax: static_cast < new_data_type > (expression)\n\n";
    std::cout << "----------TEST ONE----------\n";
    float multiplication = 4.2 * 2.15;
    int result;
    result = multiplication;
    std::cout << "Result : " << result << std::endl;
    std::cout << "----------SAME TEST BUT USING STATIC CAST----------\n";
    float multiplication1 = 4.2 * 2.15;
    int result1;
    result1 = static_cast <int> (multiplication1);
    std::cout << "Result : " <<(result1) << std::endl;

}*/

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
	{
        std::cerr << "Usage: ./Scalarconverter <literal>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}