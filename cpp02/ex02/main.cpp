/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:25:56 by ymostows          #+#    #+#             */
/*   Updated: 2024/04/19 15:25:56 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << "max is " << Fixed::max( a, b ) << std::endl;
std::cout << "min is " << Fixed::min( a, b ) << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;

if (a < b)
    std::cout << a << " < " << b <<std::endl;
else
    std::cout << a << " > " << b <<std::endl;
return 0;
}

