#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe (const PmergeMe &src)
{
    *this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src)
    {
        vector = src.vector;
        deque = src.deque;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(char **argv)
{
    for (int i = 1; argv[i]; i++)
        for (int j = 0; argv[i][j]; j++)
            if (!std::isdigit(argv[i][j]))
                throw std::runtime_error("Error: invalid parameter");

    for (int i = 1; argv[i]; i++)
    {
        int n = std::strtol(argv[i], 0, 10);
        vector.push_back(n);
        deque.push_back(n);
    }
    std::cout << "Before: ";
    printContainer(vector);
    double vectorTime = timeAndSort(vector);
    double dequeTime = timeAndSort(deque);
    std::cout << "After:  ";
    printContainer(vector);
    std::cout << std::fixed << std::setprecision(5) << "Time to process a range of " << vector.size() << " elements with std::vector: " << vectorTime << " us\n";
    std::cout << std::fixed << std::setprecision(5) << "Time to process a range of " << deque.size() << " elements with std::deque" << ": " << dequeTime << " us\n";
}