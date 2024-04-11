/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filecpy.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:49:58 by marvin            #+#    #+#             */
/*   Updated: 2024/03/11 17:49:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILECPY_HPP
#define FILECPY_HPP

#include <iostream>
#include <fstream>

class Filecpy
{
private:
	std::string _infile;
	std::string _outfile;
public:
	Filecpy(std::string filename);
	~Filecpy();

	void	replace(std::string s1, std::string s2);
};

#endif