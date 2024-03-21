#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*   generate(void)
{
    srand(time(0));
    switch (rand() % 3)
    {
        case 0: return new A;
        case 1: return new B;
        case 2: return new C;
    }
    return 0;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Identified as A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Identified as B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Identified as C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A\n";
    }
    catch (std::exception &e)
    {
        try
        {
            B &b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "B\n";
        }
        catch (std::exception &e)
        {
            try
            {
                C &c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "C\n";
            }
            catch (std::exception &e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }
}

int main()
{
    Base *p = generate();
    identify(p);
    identify(*p);
    delete p;
    return 0;
}