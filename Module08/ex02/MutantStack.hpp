#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <algorithm>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() : std::stack<T>() {};
    MutantStack(MutantStack const & src) : std::stack<T>(src) {};
    virtual ~MutantStack() {};
    MutantStack & operator=(MutantStack const & rhs)
    {
        if (this != &rhs)
            std::stack<T>::operator=(rhs);
        return *this;
    }
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    iterator begin() { return std::stack<T>::c.begin(); };
    iterator end() { return std::stack<T>::c.end(); };
    const_iterator begin() const { return std::stack<T>::c.begin(); };
    const_iterator end() const { return std::stack<T>::c.end(); };

};
template <typename T>
std::ostream& operator<<(std::ostream& os, const MutantStack<T>& mstack)
{
    for(typename MutantStack<T>::const_iterator it = mstack.begin(); it != mstack.end(); ++it)
    {
        os << *it << " ";
    }
    return os;
}
#endif