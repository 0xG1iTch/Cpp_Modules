/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:41:53 by mel-hamm          #+#    #+#             */
/*   Updated: 2025/09/18 18:35:53 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    FragTrap f1("Frank");
    f1.attack("target");
    f1.highFivesGuys();

    FragTrap f2 = f1;
    f2.attack("another target");
    f2.highFivesGuys();

    return 0;
}
