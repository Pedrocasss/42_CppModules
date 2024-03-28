#include "Span.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    {
        std::cout << "Test with 5 numbers" << std::endl;
        Span sp(5);
        sp.addNumber(-10);
        sp.addNumber(0);
        sp.addNumber(17);
        sp.addNumber(-2);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    std::cout << "-------------------------" << std::endl;

    {
        std::cout << "Test with 10000 numbers" << std::endl;
        Span sp(10000);
        for(int i = 0; i < 10000; ++i)
        {
            sp.addNumber(rand());
        }
        //sp.showNumbers();

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    std::cout << "-------------------------" << std::endl;

    {
        // test with 1 number
        std::cout << "Test with 1 number" << std::endl;
        Span sp(1);
        try
        {
            sp.addNumber(1);
            sp.showNumbers();
            std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
            std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    std::cout << "-------------------------" << std::endl;

    {
        std::cout << "Test with 0 number" << std::endl;
        Span sp(0);
        try
        {
            sp.showNumbers();
            std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
            std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    std::cout << "-------------------------" << std::endl;

    {
        std::cout << "Test with 10001 numbers and 1000 capacity" << std::endl;
        Span sp(1000);
        try
        {
            for(int i = 0; i < 10001; ++i)
            {
                sp.addNumber(rand());
            }
            sp.showNumbers();
            std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
            std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    return 0;
}