/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:25:23 by ymostows          #+#    #+#             */
/*   Updated: 2024/04/19 15:25:23 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->_value = 0;
}

Fixed::Fixed(const Fixed &to_cpy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(to_cpy.getRawBits());
}

Fixed& Fixed::operator=( const Fixed &original )
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &original)
        this->_value = original.getRawBits();
    return *this;
}

int    Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void  Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}