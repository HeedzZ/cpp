/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:24:51 by ymostows          #+#    #+#             */
/*   Updated: 2024/04/19 15:24:51 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->_value = 0;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
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

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = n << _bits;
}

Fixed::Fixed(const float n)
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(n * ( 1 << _bits));
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

float   Fixed::toFloat(void) const
{
    return static_cast<float>(this->getRawBits()) / (1 << _bits);
}

int Fixed::toInt(void) const
{
    return this->_value >> _bits;
}

std::ostream & operator<<( std::ostream &o, Fixed const &i )
{
    o << i.toFloat();
    return o;
}