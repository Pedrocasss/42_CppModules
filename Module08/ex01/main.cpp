#include "Span.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    srand((time(0)));
    std::cout << "Test with 5 numbers" << std::endl;
    Span sp1(5);
    sp1.addNumber(-10);
    sp1.addNumber(0);
    sp1.addNumber(17);
    sp1.addNumber(-2);
    sp1.addNumber(11);
    sp1.showNumbers();
    std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp1.longestSpan() << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << "Test with 10000 numbers" << std::endl;
    Span sp2(30000);
    for(int i = 0; i < 30000; ++i)
    {
        sp2.addNumber(rand() % 1000000);
    }
    sp2.showNumbers();
    std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << "Test with 2 number" << std::endl;
    Span sp3(2);
    try
    {
        sp3.addNumber(21);
        sp3.addNumber(22);
        sp3.showNumbers();
        std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
    std::cout << "Test with 0 number" << std::endl;
    Span sp4(0);
    try
    {
        std::cout << "Shortest span: " << sp4.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp4.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
    std::cout << "Test with 10000 numbers and 1000 capacity" << std::endl;
    Span sp5(1000);
    try
    {
        sp5.addNumbers(10, 10010);
        sp5.showNumbers();
        std::cout << "Shortest span: " << sp5.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp5.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
    std::cout << "Test with some numbers with improved addNumber()" << std::endl;
    try
    {
        Span sp6(5);
        sp6.addNumbers(1, 5);
        sp6.showNumbers();
        std::cout << "Shortest span: " << sp6.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp6.longestSpan() << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}