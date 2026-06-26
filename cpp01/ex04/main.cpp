/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:34:41 by mel-hamm          #+#    #+#             */
/*   Updated: 2025/08/17 09:43:44 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

bool replaceInFile(const std::string &filename, const std::string &s1, const std::string &s2)
{
    std::ifstream inputFile(filename);
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        return false;
    }
    std::ofstream outputFile(filename + ".replace");
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Could not create the output file." << std::endl;
        return false;
    }
    std::string line;
    std::getline(inputFile, line, '\0');
    size_t pos = 0;
    while ((pos = line.find(s1, pos)) != std::string::npos)
    {
        line.erase(pos, s1.length());
        line.insert(pos, s2);
        pos += s2.length();
    }
    outputFile << line << std::endl;
    inputFile.close();
    outputFile.close();

    return true;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./sed <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (replaceInFile(filename, s1, s2))
    {
        std::cout << "File has been successfully processed and saved as " << filename << ".replace" << std::endl;
    }
    else
    {
        std::cerr << "An error occurred while processing the file." << std::endl;
        return 1;
    }

    return 0;
}
