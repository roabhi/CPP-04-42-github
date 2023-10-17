// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Character.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/15 17:02:27 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/17 23:30:37 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Character.hpp"

Character::Character(void) : _name("anonymous"), _idx(0), _floorCapacity(4)
{
	std::cout << "Character default constructor called" << std::endl;

	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	AMateria** newFloor = new AMateria*[this->_floorCapacity];
	this->_floor = newFloor;
	for (unsigned int i = 0; i < _floorCapacity; i++)
		this->_floor[i] = NULL;
	
	return;
}

Character::Character(std::string name) : _name(name), _idx(0), _floorCapacity(4)
{
	std::cout << "Character name constructor called for "<< this->getName() << std::endl;

	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	AMateria** newFloor = new AMateria*[this->_floorCapacity];
	this->_floor = newFloor;
	for (unsigned int i = 0; i < _floorCapacity; i++)
		this->_floor[i] = NULL;

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
	this->_name = inst.getName();

	this->_floorCapacity = inst.getFloorCapacity();
	this->_floorIdx = inst.getFloorIdx();

	AMateria** newFloor = new AMateria*[4];
	this->_floor = newFloor;
	for (unsigned int i = 0; i < _floorCapacity; i++)
		this->_floor[i] = NULL;
	
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
		std::cout << "Character " << this->getName() << " has no space left!" << std::endl;
		this->dropMateria(*m);
	}
		
		
		
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (this->_inventory[idx] != NULL)
		this->_inventory[idx]->use(target);
}

void		Character::dropMateria(AMateria &materia)
{
	if ((this->_floorCapacity - 1 <= this->_floorIdx))
	{
		this->_floorCapacity += 4;
		AMateria** newFloor = new AMateria*[this->_floorCapacity];
		for (unsigned int i = 0; i < this->_floorCapacity - 4; i++)
			newFloor[i] = this->_floor[i];
		delete [] this->_floor;
		AMateria** auxFloor = new AMateria*[this->_floorCapacity];
		this->_floor = auxFloor;
		for (unsigned int i = 0; i < _floorCapacity - 4; i++)
			this->_floor[i] = newFloor[i];
		this->_floor[this->_floorIdx] = &materia;
		this->_floorIdx++;
		delete [] newFloor;
	}
	else
	{
		this->_floor[this->_floorIdx] = &materia;
		this->_floorIdx++;
	}
}



unsigned int Character::getFloorCapacity() const
{
	return (this->_floorCapacity);
}

unsigned int Character::getFloorIdx() const
{
	return (this->_floorIdx);
}


void Character::listMaterias() const
{
	std::string materia;
	std::string	name;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
		{
			materia = this->_inventory[i]->getType();
			name = this->getName();
			std::cout << name << " materia " << i << " is " << materia << std::endl;
		}
	}
}
