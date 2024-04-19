/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:24:10 by ymostows          #+#    #+#             */
/*   Updated: 2024/04/19 15:24:10 by ymostows         ###   ########.fr       */
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

	bool    operator>(const Fixed &obj) const;
	bool    operator<(const Fixed &obj) const;
	bool    operator>=(const Fixed &obj) const;
	bool    operator<=(const Fixed &obj) const;
	bool    operator==(const Fixed &obj) const;
	bool    operator!=(const Fixed &obj) const;

	Fixed	operator+(const Fixed &obj) const;
	Fixed	operator-(const Fixed &obj) const;
	Fixed	operator*(const Fixed &obj) const;
	Fixed	operator/(const Fixed &obj) const;

	Fixed&  operator++(void);
    Fixed   operator++(int);
    Fixed&  operator--(void);
    Fixed   operator--(int);

	static Fixed&		min(Fixed &n1, Fixed &n2);
	static Fixed&		max(Fixed &n1, Fixed &n2);
	static Fixed const&	min(const Fixed &n1, const Fixed &n2);
	static Fixed const&	max(const Fixed &n1, const Fixed &n2);
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif