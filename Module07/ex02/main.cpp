#include "Array.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

/*
#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
}*/


int main(void)
{
    srand(time(0));
    Array<float> numbers(10);
    Array<float> mirror(10);
    for (float i = 0; i < 10; i++)
    {
        const float value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    for (float i = 0; i < 10; i++)
    {
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
        std::cout << "mirror[" << i << "] = " << mirror[i] << std::endl;
    }
    try
    {
        numbers[10] = 0;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        numbers[-1] = 0;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}