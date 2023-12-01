#ifndef FIXED_HPP
# define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
    private:
    int number;
    static const int fracBits = 8;
    public:
    Fixed (void);
    Fixed(Fixed const & copy);
    Fixed (const int value);
    Fixed (const float value);
    ~Fixed(void);

    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
    Fixed &operator=(const Fixed &other);

    bool operator<(const Fixed &fixed) const;
	bool operator>(const Fixed &fixed) const;
	bool operator==(const Fixed &fixed) const;
	bool operator!=(const Fixed &fixed) const;
	bool operator<=(const Fixed &fixed) const;
	bool operator>=(const Fixed &fixed) const;

    Fixed operator+(const Fixed &fixed) const;
	Fixed operator-(const Fixed &fixed) const;
	Fixed operator*(const Fixed &fixed) const;
	Fixed operator/(const Fixed &fixed) const;
    Fixed& operator++(void);
	Fixed operator++(int);
	Fixed& operator--(void);
	Fixed operator--(int);

    static Fixed& min(Fixed &number1, Fixed &number2);
	static const Fixed& min(const Fixed &number1, const Fixed &fixed2);
	static Fixed& max(Fixed &number1, Fixed &fixed2);
	static const Fixed& max(const Fixed &number1, const Fixed &fixed2);
};
std::ostream &	operator<<(std::ostream & out, Fixed const & number);



#endif