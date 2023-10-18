// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Cure.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/18 19:52:52 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/18 20:06:30 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{

public:

	Cure(void);
	Cure(const Cure &inst);
	Cure& operator=(const Cure& inst);
	AMateria* clone() const;
	void     use(ICharacter& target) const;
	~Cure(void);
};

#endif
