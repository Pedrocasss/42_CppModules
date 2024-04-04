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
        sortFordJohnson(container);
        return (double)(clock() - start) / CLOCKS_PER_SEC * 1000000;
    }

    template <typename T>
    void sortFordJohnson(T &container)
    {
        T copy, smaller;
        int size = container.size() - 1;
        int i = 0;

        if (container.size() < 2)
            return ;
        copy = container;
        container.clear();
        while (i < size)
        {
            if (copy[i] > copy[i + 1]) {
                container.push_back(copy[i]);
                smaller.push_back(copy[i + 1]);
            }
            else {
                container.push_back(copy[i + 1]);
                smaller.push_back(copy[i]);
            }
            i += 2;
        }
        if (copy.size() % 2)
            container.push_back(copy[i]);
        sortFordJohnson(container);
        binaryJacobsthalInsert(container, smaller);
    }

    template <typename T>
    int calculateCurrentIndex(const T &merge, int index) {
        return (jacobsthal[index] < (int)merge.size() ? jacobsthal[index] : merge.size() - 1);
    }

    template <typename T>
    typename T::iterator findInsertionPoint(T &base, const T &merge, int current) {
        return std::lower_bound(base.begin(), base.end(), merge[current]);
    }

    template <typename T>
    void insertElementAtPoint(T &base, typename T::iterator where, const T &merge, int current) {
        base.insert(where, merge[current]);
    }

    template <typename T>
    void binaryJacobsthalInsert(T &base, T &merge) {
        typename T::iterator where;
        int index = 0, current;

        do {
            index++;
            current = calculateCurrentIndex(merge, index);
            while (current > jacobsthal[index - 1]) {
                where = findInsertionPoint(base, merge, current);
                insertElementAtPoint(base, where, merge, current);
                current--;
            }
        } while (jacobsthal[index] < (int)merge.size());
    }

private:
    std::vector<int> vector;
    std::deque<int> deque;
    static const int jacobsthal[35];
};

#endif