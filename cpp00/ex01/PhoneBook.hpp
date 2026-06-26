/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:50:57 by mel-hamm          #+#    #+#             */
/*   Updated: 2025/08/10 11:11:12 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook
{
    public:
        PhoneBook();
    
        void add(const Contact &c);
        int list() const;
        void show(int idx) const;
    private:
        Contact _contacts[8];
        int _count;
        int _next;
};
