#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <stdexcept>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>

class PmergeMe
{
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe &src);
    PmergeMe &operator=(const PmergeMe &src);
    PmergeMe(char **argv);

    template <typename T>
    void printContainer(const T &container)
    {
        for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
            std::cout << *it << ' ';
        std::cout << std::endl;
    }

    template <typename T>
    double timeAndSort(T &container)
    {
        clock_t start = clock();
        fordJohnsonSort(container, 0, container.size() - 1);
        return (double)(clock() - start) / CLOCKS_PER_SEC * 1000000;
    }

    template <typename T>
void fordJohnsonSort(T &container, int left, int right)
{
    if (left < right)
    {
        // Divide o array em pares e ordena cada par
            for (int i = left; i < right; i += 1)
            {
                if (container[i] > container[i + 1])
                {
                    std::swap(container[i], container[i + 1]);
                }
            }

            // Aplica recursivamente para os pares maiores
            int mid = (left + right) / 2;
            fordJohnsonSort(container, left, mid);
            fordJohnsonSort(container, mid + 1, right);

            // Mescla os pares ordenados
            std::vector<int> merged;
            int i = left, j = mid + 1;
            while (i <= mid && j <= right)
            {
                if (container[i] <= container[j])
                {
                    merged.push_back(container[i]);
                    i += 1;
                }
                else
                {
                    merged.push_back(container[j]);
                    j += 1;
                }
            }
            while (i <= mid)
            {
                merged.push_back(container[i]);
                i += 1;
            }
            while (j <= right)
            {
                merged.push_back(container[j]);
                j += 1;
            }
            for (int k = 0; k < static_cast<int>(merged.size()); ++k)
            {
                container[left + k] = merged[k];
            }

            // Insere os elementos restantes na sequência ordenada final em binário
            for (int i = left + 1; i <= right; i += 1)
            {
                typename T::iterator insertionPoint = std::lower_bound(container.begin() + left, container.begin() + i, container[i]);
                std::rotate(insertionPoint, container.begin() + i, container.begin() + i + 1);

            }
        }
    }


private:
    std::vector<int> vector;
    std::deque<int> deque;
};

#endif
