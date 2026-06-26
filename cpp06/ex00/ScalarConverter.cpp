#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
    *this = other;
}

ScalarConverter::~ScalarConverter(){}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return *this;
}

void possibility_toPrint(float f)
{
	if (isnan(f) || isinf(f) || f < 0 || f > 127)
	    std::cout << "char: impossible" << std::endl;
	else
	{
		int tmp = static_cast<int>(f);
		if (f != static_cast<float>(tmp))
			std::cout << "char: impossible" << std::endl;
		else
		{
			if (!std::isprint(static_cast<unsigned char>(tmp)))
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: '" << static_cast<char>(tmp) << "'" << std::endl;
		}
	}
	if (isnan(f) || isinf(f) || f < INT_MIN || f > INT_MAX)
		std::cout << "Int: impossible" << std::endl;
	else
		std::cout << "Int: " << static_cast<int>(f) << std::endl;
}
void possibility_toPrint(double d)
{
	if (isnan(d) || isinf(d) || d < 0 || d > 127)
	    std::cout << "char: impossible" << std::endl;
	else
	{
		int tmp = static_cast<int>(d);
		if (d != static_cast<double>(tmp))
			std::cout << "char: impossible" << std::endl;
		else
		{
			if (!std::isprint(static_cast<unsigned char>(tmp)))
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: '" << static_cast<char>(tmp) << "'" << std::endl;
		}
	}
	if (isnan(d) || isinf(d) || d < INT_MIN || d > INT_MAX)
		std::cout << "Int: impossible" << std::endl;
	else
		std::cout << "Int: " << static_cast<int>(d) << std::endl;
}
void char_branch(char c)
{
	if (!std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "Int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "Double: " << static_cast<double>(c) << std::endl;
}

void int_branch(int i)
{
	if (i < 0 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<unsigned char>(i)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "Int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
	std::cout << "Double: " << static_cast<double>(i) << std::endl;
}

void float_branch(float f)
{
	possibility_toPrint(f);
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "Double: " << static_cast<double>(f) << std::endl;
}

void double_branch(double d)
{
	possibility_toPrint(d);
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	std::cout << "Double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string& str)
{
    Type t; char c; int i; float f; double d;
    if (str.length() == 1 && !std::isdigit(str[0]))
    {
		t = CHAR;
		c = str[0];
	}
	else if (str == "nan" || str == "+inf" || str == "-inf")
    {
		t = DOUBLE;
		std::istringstream iss(str);
	    if (!(iss >> d) || !iss.eof())
		{
            std::cout << "Error: Invalid input" << std::endl;
	        return;
		}
    }
	else if (!str.empty() && str[str.length() - 1] == 'f')
	{
	    t = FLOAT;
	    std::string num = str.substr(0, str.length() - 1);
	    std::istringstream iss(num);
	    if (!(iss >> f) || !iss.eof())
	    {
	        std::cout << "Error: Invalid input" << std::endl;
	        return;
	    }
	}
	else if (str.find('.') != std::string::npos)
    {
		t = DOUBLE;
		std::istringstream iss(str);
	    if (!(iss >> d) || !iss.eof())
		{
            std::cout << "Error: Invalid input" << std::endl;
	        return;
		}
    }
	else
	{
        t = INT;
		std::istringstream iss(str);
	    long tmp;
	    if (!(iss >> tmp) || !iss.eof())
		{
            std::cout << "Error: Invalid input" << std::endl;
			return;
		}
	    if (tmp < INT_MIN || tmp > INT_MAX)
		{
            std::cout << "Error: Invalid input" << std::endl;
			return;	
		}
	    i = static_cast<int>(tmp); 
    }
	if (t == CHAR)
		char_branch(c);
	else if (t == FLOAT)
		float_branch(f);
	else if (t == DOUBLE)
		double_branch(d);
	else if (t == INT)
		int_branch(i);
}