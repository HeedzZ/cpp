/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceFile.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:49:45 by marvin            #+#    #+#             */
/*   Updated: 2024/03/11 17:49:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Filecpy.hpp"

Filecpy::Filecpy(std::string filename) : _infile(filename)
{
	this->_outfile = this->_infile + ".replace";
}

Filecpy::~Filecpy(void)
{	
}

void	Filecpy::replace( std::string s1, std::string s2)
{
	std::ifstream ifs(this->_infile.c_str());
	if (ifs.is_open())
	{
		std::string content;
		if (std::getline(ifs, content, '\0'))
		{
			std::ofstream	ofs(this->_outfile.c_str());
			size_t			pos = content.find(s1);
			while (pos != std::string::npos)
			{
				content.erase(pos, s1.length());
				content.insert(pos, s2);
				pos = content.find(s1);
			}
			ofs << content;
			ofs.close();
		}
		else
			std::cerr << "Empty file.\n";
		ifs.close();
	}
	else
		std::cerr << "Unable to open the file.\n";
}