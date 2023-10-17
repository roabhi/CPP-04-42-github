// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ICharacter.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/15 16:43:41 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/17 21:20:25 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <iostream>
#include "../materia/AMateria.hpp"

class AMateria;

class ICharacter {

public:

	virtual ~ICharacter() {}
	virtual std::string const & getName(void) const = 0;
	virtual void equip(AMateria* m) = 0;
	//virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;

};


#endif
