/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:31:12 by marvin            #+#    #+#             */
/*   Updated: 2024/03/12 16:31:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					_value;
	static const int	_bits = 8;

public:
	Fixed(void);
	Fixed(const Fixed &to_cpy);
	Fixed&	operator=(const Fixed &original);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int	const raw);
};

#endif