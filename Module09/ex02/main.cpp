#include "PmergeMe.hpp"

bool isSorted(const std::vector<int>& numbers)
{
    for (size_t i = 1; i < numbers.size(); i++)
    {
        if (numbers[i] < numbers[i-1])
            return false;
    }
    return true;
}

int main(int argc, char **argv)
{
  try
  {
    if (argc < 2)
      throw std::runtime_error("Usage: ./PmergeMe ARGS");
    std::vector<int> args;
    for (int i = 1; i < argc; i++) {
        std::istringstream iss(argv[i]);
        int num;
        iss >> num;
        args.push_back(num);
    }
    if (isSorted(args))
        throw std::runtime_error("Input is already sorted");
    PmergeMe pmergeMe(argv);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }
}