/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:44:43 by marvin            #+#    #+#             */
/*   Updated: 2024/03/11 16:44:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Filecpy.hpp"

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace <filename> <to_find> <replace>." << std::endl;
		return (0);
	}
	else
	{
		Filecpy Filecpy(argv[1]);
		Filecpy.replace(argv[2], argv[3]);
	}
	return (0);
}
