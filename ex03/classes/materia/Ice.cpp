// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ice.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/15 19:46:47 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/18 20:15:14 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Ice.hpp"

Ice::Ice(void) :AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
	
	return ;
}

Ice::Ice(const Ice &inst) : AMateria("ice")
{
	std::cout << "Ice copy constructor called" << std::endl;
	this->_type = inst._type;
	*this = inst;
}

Ice::~Ice(void)
{
	std::cout << "Ice default destructor called" << std::endl;
	return ;
}

Ice& Ice::operator=(const Ice& inst)
{
	std::cout << "Ice assigment operator called" <<  std::endl;
	this->_type = inst._type;
	return (*this);
}

AMateria* Ice::clone() const
{
	std::cout << "Ice clone called!" << std::endl;
	AMateria* new_ice = new Ice(*this);
	return (new_ice);
}

void Ice::use(ICharacter& target) const
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" <<std::endl;
}
