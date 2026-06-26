/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 13:04:32 by mel-hamm          #+#    #+#             */
/*   Updated: 2025/08/10 13:23:17 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie* horde = zombieHorde(3, "Foo");

    for (int i = 0; i < 3; ++i)
    {
        horde[i].announce();
    }

    operator delete[] (horde);

    return 0;
}
