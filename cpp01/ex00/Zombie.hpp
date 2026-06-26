/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 12:29:04 by mel-hamm          #+#    #+#             */
/*   Updated: 2025/08/15 12:14:16 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <new>

class Zombie
{
    private:
	    std::string name;
    public:
	    Zombie(std::string name);
        ~Zombie();

	    void announce(void);
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);

#endif