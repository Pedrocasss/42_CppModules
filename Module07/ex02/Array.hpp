#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
        T * _array;
        unsigned int _size;
    public:
        Array(void) : _array(NULL), _size(0) {}
        Array(unsigned int n) : _array(new T[n]), _size(n) {}
        Array(Array const & src) : _array(NULL), _size(0)
        { 
            *this = src;
        }
        ~Array(void) 
        { 
            delete [] _array; 
        }

        Array & operator=(Array const & rhs)
        {
            if (this != &rhs)
            {
                delete [] _array;
                _size = rhs._size;
                _array = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    _array[i] = rhs._array[i];
            }
            return *this;
        }

        class outOfBounds: public std::exception
		{
			public:
				virtual const char* what() const throw()
                {
					return ("Array index is out of bounds");
                };
		};

        T & operator[](int i)
        {
            if (i >= static_cast <int> (_size) || i < 0)
                throw outOfBounds();
            return _array[i];
        }

        T const & operator[](int i) const
        {
            if (i >= static_cast <int> (_size) || i < 0)
                throw outOfBounds();
            return _array[i];
        }
        unsigned int size(void) const
        {
            return _size; 
        }

};



#endif