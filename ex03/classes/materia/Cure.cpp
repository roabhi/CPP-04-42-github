// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Cure.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/18 19:57:12 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/21 20:48:15 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
	
	return ;
}

Cure::Cure(const Cure &inst) : AMateria("cure")
{
	std::cout << "Cure copy constructor called" << std::endl;
	this->_type = inst._type;
	*this = inst;
}

Cure::~Cure(void)
{
	std::cout << "Cure default destructor called" << std::endl;
	return ;
}

Cure& Cure::operator=(const Cure& inst)
{
	std::cout << "Cure assigment operator called" <<  std::endl;
	if (this != &inst) {
		this->_type = inst._type;
	}
	return (*this);
}

AMateria* Cure::clone() const
{
	std::cout << "Cure clone called!" << std::endl;
	AMateria* new_cure = new Cure(*this);
	return (new_cure);
}

void Cure::use(ICharacter& target) const
{
	std::cout << "* heals " << target.getName() << " wounds *" <<std::endl;
}
