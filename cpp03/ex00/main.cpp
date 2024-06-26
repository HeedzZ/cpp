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

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap1("Clap1");
	ClapTrap clap2("Clap2");

	clap1.attack("Clap2");
	clap1.beRepaired(1);
	clap1.takeDamage(11);
	return 0;
}
