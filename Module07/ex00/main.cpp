#include "whatever.hpp"

int main(void)
{
    std::cout << "\t\tTEST WITH TWO INTEGERS\n";
    int a_int = 10;
    int b_int = 20;
    int int_max = max(a_int, b_int);
    int int_min = min(a_int, b_int);

    std::cout <<"Value of INT A -> " << a_int << std::endl;
    std::cout <<"Value of INT B -> " << b_int << std::endl;
    std::cout << "----------" << std::endl;
    std::cout <<"Max value: -> " << int_max << std::endl;
    std::cout <<"Min value: -> " << int_min << std::endl;
    swap(a_int, b_int);
    std::cout << "Swap values: A-> " << a_int << "\tB-> " << b_int << std::endl;

    std::cout << "\t\tTEST WITH TWO CHARS\n";
    char a_char = 'c';
    char b_char = 'z';
    char char_max = max(a_char, b_char);
    char char_min = min(a_char, b_char);

    std::cout <<"Value of CHAR A -> " << a_char << std::endl;
    std::cout <<"Value of CHAR B -> " << b_char << std::endl;
    std::cout << "----------" << std::endl;
    std::cout <<"Max value: -> " << char_max << std::endl;
    std::cout <<"Min value: -> " << char_min << std::endl;
    swap(a_char, b_char);
    std::cout << "Swap values: A-> " << a_char << "\tB-> " << b_char << std::endl;
    std::cout << "\t\tSUBJECT MAIN\n";
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;

}