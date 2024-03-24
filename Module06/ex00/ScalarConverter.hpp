#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <limits>
#include <sstream>

class ScalarConverter
{
	private:
		static void	processValues(double value);
		static void toChar(double value);
		static void toInt(double value);
		static void toFloat(double value);
		static void toDouble(double value);
		static std::string detectType(const std::string &input);
		ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
		ScalarConverter & operator=(ScalarConverter const & src);
		~ScalarConverter();
	public:
		static void convert(const std::string &input);
};

#endif