// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AMateria.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/15 18:24:12 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/21 21:23:04 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("unknown")
{
	std::cout << "Default constructor for AMateria " << this->getType() << std::endl;

	return;
}

AMateria::AMateria(const std::string & type) : _type(type)
{
	std::cout << "Name constructor for AMateria " << this->getType() << std::endl;

	return ;
}

AMateria::AMateria(const AMateria &inst)
{
	std::cout << "Copy constructor for AMateria " << this->getType() << std::endl;
    //this->_type = inst._type;
	*this = inst;
}

AMateria& AMateria::operator=(const AMateria& inst)
{
	std::cout << "AMateria assigment operator called " << std::endl;
	if (this != &inst)
		this->_type = inst._type;
	return (*this);
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria default destructor called" << std::endl;
	return ;
}


std::string const & AMateria::getType() const
{
	return(this->_type);
}

void AMateria::use(ICharacter& target) const
{
	std::cout << "* shoots an ice bolt at " << target.getName() << "*" <<std::endl;
}
