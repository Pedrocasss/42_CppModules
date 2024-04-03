#include "Span.hpp"

Span::Span(void) : _n(0)
{
    std::cout << "Default Span constructor called" << std::endl;
}

Span::Span(unsigned int n) : _n(n)
{
    std::cout << "Parametric Span constructor called" << std::endl;
}

Span::Span(Span const & src)
{
    std::cout << "Copy Span constructor called" << std::endl;
    *this = src;
}

Span::~Span(void)
{
    std::cout << "Destructor Span called" << std::endl;
}

Span & Span::operator=(Span const & rhs)
{
    std::cout << "Assignation Span operator called" << std::endl;
    if (this != &rhs)
    {
        _n = rhs._n;
        _v = rhs._v;
    }
    return *this;
}

void Span::addNumber(int n)
{
    if (_v.size() < _n)
        _v.push_back(n);
    else
        throw Span::outOfRangeException();
}

void Span::addNumbers(int start, int end)
{
    if (end < start)
        throw std::invalid_argument("End cannot be less than start");

    int rangeSize = end - start + 1;
    if (_v.size() + rangeSize > _n)
        throw Span::outOfRangeException();

    for (int i = start; i <= end; ++i) {
        _v.push_back(i);
    }
}

int Span::shortestSpan(void)
{
    if (_v.size() < 2)
        throw NoSpanException();
    std::vector<int> v = _v;
    std::sort(v.begin(), v.end());
    int min = v[1] - v[0];
    for (unsigned int i = 2; i < v.size(); i++)
    {
        if (v[i] - v[i - 1] < min)
            min = v[i] - v[i - 1];
    }
    return min;
}

int Span::longestSpan(void)
{
    if (_v.size() < 2)
        throw NoSpanException();
    return *std::max_element(_v.begin(), _v.end()) - *std::min_element(_v.begin(), _v.end());
}

const char* Span::NoSpanException::what() const throw()
{
    return ("No span to find ):");
}

const char* Span::outOfRangeException::what() const throw()
{
    return ("Out of range ):");
}

void Span::showNumbers(void)
{
    for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}




