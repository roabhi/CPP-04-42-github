// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Character.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/15 17:02:27 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/17 21:32:54 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Character.hpp"

Character::Character(void) : _name("anonymous"), _idx(0)
{
	std::cout << "Character default constructor called" << std::endl;

	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;

	return;
}

Character::Character(std::string name) : _name(name), _idx(0)
{
	std::cout << "Character name constructor called for "<< this->getName() << std::endl;

	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;

	return;
}

Character::Character(const Character& inst)
{
	std::cout << "Character copy constructor called" << std::endl;

	for ( int i = 0; i < 4; i++ )
	{
		this->_inventory[ i ] = NULL;
		if ( inst._inventory[ i ] != NULL )
		  this->_inventory[ i ] = inst._inventory[ i ]->clone();
	}

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

void Character::equip(AMateria* m)
{
	unsigned int is_equipped = 0;

	if ( this->_idx == -1 || m == NULL)
	{
		std::cout << "Character " << this->_name << " couldn' t equip!." << std::endl;
		return ;
	}

	for (int idx = 0; idx < 4; idx++)
	{
		if (this->_inventory[idx] == m)
			return ; // trying to add the same Materia
	}

	for (int idx = 0; idx < 4; idx++)
	{
		if (this->_inventory[idx] == NULL)
		{
			this->_inventory[idx] = m;
			std::cout << "Character " << this->getName() << " equiped " << m->getType() << " at " << idx << std::endl;
			is_equipped = 1;
			return ;
		}
	}

	if (!is_equipped)
	{
		std::cout << "Character " << this->getName() << " has no space left!e" << std::endl;
		//this->addToFloor(*m);
	}
		
		
		
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (this->_inventory[idx] != NULL)
		this->_inventory[idx]->use(target);
}
