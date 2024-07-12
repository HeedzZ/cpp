/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:57:34 by ymostows          #+#    #+#             */
/*   Updated: 2024/04/26 15:57:34 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
    std::cout << "Brain created." << std::endl;
}

Brain::~Brain( void )
{
    std::cout << "Brain destroyed." << std::endl;
}

Brain::Brain( const Brain& src )
{
    *this = src;
}

Brain& Brain::operator=( const Brain& rhs )
{
    std::cout << "Brain copy called." << std::endl;
    if ( this != &rhs ) {
        for ( int i = 0; i < 100; i++ )
            this->_ideas[i] = rhs._ideas[i];
    }
    return *this;
}