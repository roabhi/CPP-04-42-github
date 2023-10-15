// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Character.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/15 17:02:27 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/15 18:15:21 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Character.hpp"

Character::Character(void) : _name("anonymous"), _idx(0)
{
	std::cout << "Character default constructor called" << std::endl;

	return;
}

Character::Character(std::string name) : _name(name), _idx(0)
{
	std::cout << "Character name constructor called for "<< this->getName() << std::endl;

	return;
}

Character::Character(const Character& inst)
{
	std::cout << "Character copy constructor called" << std::endl;

	this->_idx = 0; // This needs to return the current idx
	this->_name = this->getName();
	*this = inst;
}

Character& Character::operator=(const Character& inst)
{

	std::cout << "Character assigment operator called" << std::endl;

	if (this != &inst)
	{
		this->_name = this->getName();
		this->_idx = 0;
	}	

	return (*this);
}

Character::~Character(void)
{
	std::cout << "Character default destructor called for " << this->getName() << std::endl;

	return ;
}

std::string const & Character::getName(void) const
{
	return (this->_name);
}
