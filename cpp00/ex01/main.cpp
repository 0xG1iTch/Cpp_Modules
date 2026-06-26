/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:50:56 by mel-hamm          #+#    #+#             */
/*   Updated: 2025/08/10 11:12:17 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

bool containsNonPrintableOrTab(const std::string& input)
{
    for (size_t i = 0; i < input.length(); ++i)
    {
        if (!std::isprint(input[i]) || input[i] == '\t')
            return true;
    }
    return false;
}

int main()
{
    PhoneBook pb;
    std::string cmd;

    while (true)
    {
        std::cout << "CMD (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, cmd))
            break;
        if (cmd == "EXIT")
            break;
        else if (cmd == "ADD")
        {
            Contact c;
            std::string prompts[5] = {
                "First Name", "Last Name", "Nickname", "Phone", "Secret"
            };
            std::string input;
            for (int i = 0; i < 5; ++i)
            {
                do
                {
                    std::cout << prompts[i] << ": ";
                    if (!std::getline(std::cin, input))
                    {
                        std::cout << "\nInput error detected. Exiting program." << std::endl;
                        return 1;
                    }
                }
                while (input.empty() || containsNonPrintableOrTab(input));
                c.setField(i, input);
            }
            pb.add(c);
        }
        else if (cmd == "SEARCH")
        {
            if (pb.list() == -1)
                continue;
            std::cout << "Index: ";
            std::getline(std::cin, cmd);
            int idx = std::atoi(cmd.c_str());
            pb.show(idx);
        }
    }
    return 0;
}
