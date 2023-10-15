// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ice.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/15 19:42:55 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/15 20:00:19 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	
public:

	Ice(void);
	Ice(const Ice &inst);
	Ice& operator=(const Ice& inst);
	AMateria* clone() const;
	void      use(ICharacter& target) const;
	~Ice(void);
	
};

#endif
