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
	ClapTrap clap("Karim");
	ScavTrap opp1("Walid");
	ScavTrap opp2(opp1);

	clap.attack("la police");
	opp1.attack( "la police" );
    opp1.takeDamage( 10 );
    opp1.beRepaired( 10 );
    opp1.guardGate();
	return 0;
}
