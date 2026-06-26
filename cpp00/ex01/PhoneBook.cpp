/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:51:03 by mel-hamm          #+#    #+#             */
/*   Updated: 2025/08/10 11:11:22 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _count(0), _next(0) {}

void PhoneBook::add(const Contact &c)
{
    _contacts[_next] = c;
    _next = (_next + 1) % 8;
    if (_count < 8)
        ++_count;
}

int PhoneBook::list() const
{
    if (_count < 1)
    {
        std::cout << "The phonebook is empty.\n";
        return -1;
    }
    std::cout << std::right;
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First" << "|"
              << std::setw(10) << "Last" << "|"
              << std::setw(10) << "Nick" << "\n";

    for (int i = 0; i < _count; ++i)
    {
        std::cout << std::setw(10) << i << "|";
        for (int f = 0; f < 3; ++f)
        {
            std::string s = _contacts[i].getField(f);
            if (s.length() > 10)
                s = s.substr(0, 9) + ".";
            std::cout << std::setw(10) << s << (f < 2 ? "|" : "\n");
        }
    }
    return 0;
}

void PhoneBook::show(int idx) const
{
    if (idx < 0 || idx >= _count)
    {
        std::cout << "Invalid index\n";
        return;
    } 
    const char* labels[5] = {
        "First Name", "Last Name", "Nickname", "Phone", "Secret"
    };

    for (int i = 0; i < 5; ++i)
        std::cout << labels[i] << ": " << _contacts[idx].getField(i) << "\n";
}
