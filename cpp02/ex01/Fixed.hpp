/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:24:56 by ymostows          #+#    #+#             */
/*   Updated: 2024/04/19 15:24:56 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					_value;
	static const int	_bits = 8;
public:
	Fixed(void);
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed &to_cpy);
    Fixed& operator=(const Fixed &original);
	~Fixed();

	int 	getRawBits(void) const;
	void 	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif