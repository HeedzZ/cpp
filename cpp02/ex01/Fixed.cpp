/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:31:09 by marvin            #+#    #+#             */
/*   Updated: 2024/03/12 16:31:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->_value = 0;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &to_cpy ) {
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(to_cpy.getRawBits());
}

Fixed::Fixed( const int n ) : _value( n << _bits ) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float n ) : _value( roundf( n * ( 1 << _bits ) ) ) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=( const Fixed &original ) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &original)
        this->_value = original.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void    Fixed::setRawBits( int const raw ) {
    this->_value = raw;
}

float   Fixed::toFloat( void ) const {
    return static_cast<float>( this->getRawBits() ) / ( 1 << _bits );
}

int     Fixed::toInt( void ) const {
    return this->_value >> _bits;
}

std::ostream & operator<<( std::ostream & o, Fixed const & i )
{
    o << i.toFloat();
    return o;
}