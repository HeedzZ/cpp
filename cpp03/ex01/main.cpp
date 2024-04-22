/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:18:00 by ymostows          #+#    #+#             */
/*   Updated: 2024/04/04 15:18:00 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap clap1("clap1");
	ScavTrap scav1("scav1");
	ScavTrap scav2(scav1);

	clap1.attack("scav1");
	scav1.attack( "clap1" );
    clap1.takeDamage( 20 );
    scav1.beRepaired( 10 );
    scav1.guardGate();
	return 0;
}
