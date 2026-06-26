#include "BitcoinExchange.hpp"
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <algorithm>

BitcoinExchange::BitcoinExchange(){load_csv();}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) {exchange = obj.exchange;}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
    exchange = obj.exchange;
    return *this;
}


BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::load_csv()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw std::runtime_error("Error: Could not open data file");
    std::string line;
    if (!std::getline(file, line))
        throw std::runtime_error("Error: empty Data file");
    else if (line != "date,exchange_rate")
        throw std::runtime_error("Error: CSV header is missing");
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string key, value;
        if (std::getline(ss, key, ',') && std::getline(ss, value))
        {
            std::stringstream ss2(value);
            float f;
            if (!(ss2 >> f))
                throw std::runtime_error("Error: Number Conversion failed");
            exchange[key] = f;
        }
    }
    file.close();
}
bool line_formated(std::string line)
{
    size_t first = line.find(" | ");
    if (first == std::string::npos)
        return false;
    size_t last = line.rfind(" | ");
    return (first == last);
}

bool date_formated(std::string date)
{
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (int i = 0; i < 10; ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    if(month == 2 && day > 29)
        return false;
    return true;
}

void BitcoinExchange::input_processing(std::string input_file)
{
    if (exchange.size() < 1)
        throw std::runtime_error("Error: no Data available to fetch");
    std::ifstream file(input_file);
    if (!file.is_open())
        throw std::runtime_error("Error: Could not open input file");
    std::string line;
    if (!std::getline(file, line))
        throw std::runtime_error("Error: File is empty");
    else if (line != "date | value")
        throw std::runtime_error("Error: Input header is missing");
    while (std::getline(file, line))
    {
        if (!line_formated(line))
            std::cout << "Error: bad input => " << line << std::endl;
        else
        {
            std::stringstream ss(line);
            std::string key, value;
            if (std::getline(ss, key, '|') && std::getline(ss, value))
            {
                key.pop_back();
                value.erase(value.begin(), value.begin() + 1);
                if (!date_formated(key))
                    std::cout << "Error: bad input => " << key << std::endl;
                else
                {
                    std::stringstream ss2(value);
                    float f;
                    char remaining;
                    if (!(ss2 >> f)) {
                        std::cout << "Error: bad input => "<< value << std::endl;
                        continue;
                    }
                    else if (ss2 >> remaining) {
                        std::cout << "Error: bad input => " << value << std::endl;
                        continue;
                    }
                    else if (f < 0 || value[0] == '-') {
                        std::cout << "Error: not a positive number." << std::endl;
                        continue;
                    }
                    else if (f > 1000) {
                        std::cout << "Error: too large a number." << std::endl;
                        continue;
                    }
                    std::map<std::string, float>::iterator it = exchange.lower_bound(key);
                    if (it != exchange.end() && it->first == key)
                        std::cout << key << " => " << value << " = " << f * it->second << std::endl;
                    else if (it == exchange.begin())
                        std::cout << "Error: Date Too early" << std::endl;
                    else {
                        it --;
                        std::cout << key << " => " << value << " = " << f * it->second << std:: endl;
                    }
                }
            }
        }
    }
    file.close();
}
