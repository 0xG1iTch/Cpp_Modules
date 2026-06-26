/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 21:35:31 by mel-hamm          #+#    #+#             */
/*   Updated: 2025/08/10 10:48:51 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"



void Contact::setField(int idx, const std::string &val)
{
    if (idx >= 0 && idx < 5)
        _fields[idx] = val;
}

std::string Contact::getField(int idx) const
{
    if (idx >= 0 && idx < 5)
        return _fields[idx];
    return std::string();
}
