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


class PmergeMe
{
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);
        PmergeMe(char **argv);
        template <typename T> void printContainer(const T &container) {
            for (typename T::const_iterator it = container.begin(); it != container.end();
                ++it)
                std::cout << *it << ' ';
            std::cout << std::endl;
        }
        template <typename T> double timeAndSort(T &container)
        {
            clock_t start = clock();
            mergeInsertSort(container, 0, container.size() - 1);
            return (double)(clock() - start) / CLOCKS_PER_SEC * 1000;
        }

        template <typename T> void mergeInsertSort(T &container, int left, int right) {
            if (left < right) {
                int mid = left + (right - left) / 2;
                mergeInsertSort(container, left, mid);
                mergeInsertSort(container, mid + 1, right);
                merge(container, left, mid, right);
            }
        }

        template <typename T> void merge(T &container, int left, int mid, int right)
        {
            int i, j, k;
            int number1 = mid - left + 1;
            int number2 = right - mid;

            T L(number1), R(number2);

            for (i = 0; i < number1; i++)
                L[i] = container[left + i];
            for (j = 0; j < number2; j++)
                R[j] = container[mid + 1 + j];
            i = 0;
            j = 0;
            k = left;
            while (i < number1 && j < number2)
            {
                if (L[i] <= R[j])
                {
                    container[k] = L[i];
                    i++;
                }
                else
                {
                    container[k] = R[j];
                    j++;
                }
                k++;
            }
            while (i < number1)
            {
                container[k] = L[i];
                i++;
                k++;
            }
            while (j < number2)
            {
                container[k] = R[j];
                j++;
                k++;
            }
        }
        private:
            std::vector<int> vector;
            std::deque<int> deque;
};

#endif