// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AMateria.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/15 18:18:19 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/21 21:14:48 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "../character/ICharacter.hpp"

class ICharacter;

class AMateria {

public:
	
	AMateria(void);
	AMateria( const std::string& type );
	AMateria(const AMateria& inst);
	AMateria& operator=(const AMateria& inst);
	virtual ~AMateria(void);
	
	std::string const & getType() const; 
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target) const;

protected:

	std::string _type;

};


#endif
