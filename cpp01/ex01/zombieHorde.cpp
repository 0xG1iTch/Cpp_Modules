/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 13:01:54 by mel-hamm          #+#    #+#             */
/*   Updated: 2025/08/10 13:22:45 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie* horde = static_cast<Zombie*> (operator new[](N * sizeof(Zombie)));

    for (int i = 0; i < N; ++i)
    {
        horde[i] = Zombie(name);
    }

    return horde;
}
