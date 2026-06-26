#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include <iomanip>
#include <sstream>

class ScalarConverter
{
    private:
        ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter	&operator=(ScalarConverter const &other);
		~ScalarConverter();
	public:
		static void	convert(const std::string& str);
};

enum Type { CHAR, INT, FLOAT, DOUBLE };
#endif