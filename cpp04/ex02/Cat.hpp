/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:30:18 by ymostows          #+#    #+#             */
/*   Updated: 2024/04/26 13:30:18 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"

class Cat : public AAnimal
{
    private:
        Brain *_brain;
    public:
        Cat( void );
        Cat( const Cat& src);
        Cat &operator=(const Cat &rhs);
        ~Cat();
        
        void makeSound() const;

};

#endif