/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:42:14 by mel-hamm          #+#    #+#             */
/*   Updated: 2025/08/10 10:48:56 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Contact
{
    public:
        void setField(int idx, const std::string &val);
        std::string getField(int idx) const;
    private:
        std::string _fields[5];
};
