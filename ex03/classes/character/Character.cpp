// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Character.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/15 17:02:27 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/21 23:58:51 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Character.hpp"

Character::Character(void) : _name("anonymous"), _idx(0), _floorCapacity(4), _floorIdx(0)
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

Character::Character(std::string name) : _name(name), _idx(0), _floorCapacity(4), _floorIdx(0)
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
		this->_name = inst._name;
		for (unsigned int i = 0; i < 4; i++)
		{
			if (this->_inventory[i] == NULL)
				std::cout << i << std::endl;
			if (this->_inventory[i] != NULL)
			{
				delete this->_inventory[i];
				this->_inventory[i] = NULL;
			}
			this->_inventory[i] = NULL;
			
			if (inst._inventory[i] == NULL)
				this->_inventory[i] = NULL;
			else if (inst._inventory[i] != NULL)
			{	
				this->_inventory[i] = inst._inventory[i]->clone();
			}
		}
	}

	this->_floorCapacity = inst.getFloorCapacity();
	this->_floorCapacity = inst.getFloorIdx();
	AMateria** newFloor = new AMateria*[this->_floorCapacity];
	if (this->_floor != NULL)
		delete [] this->_floor;
	this->_floor = newFloor;
	for (unsigned int i = 0; i < this->_floorCapacity; i++)
		this->_floor[i] = NULL;

	return (*this);
}

Character::~Character(void)
{
	std::cout << "Character default destructor called for " << this->getName() << std::endl;

	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
		{
			for (unsigned int j = 0; j < this->_floorCapacity; j++)
			{
				if (this->_floor[j] == this->_inventory[i])
					this->_floor[j] = NULL;
			}
				
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
	
	this->clearFloor();
	delete [] this->_floor;

	return ;
}



std::string const & Character::getName(void) const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	unsigned int is_equipped = 0;

	if ( m == NULL)
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
			this->_idx++;
			return ;
		}
	}

	if (!is_equipped || this->_idx == 4)
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
	else
		std::cout << this->getName() << " cannot use materia on " << target.getName() << std::endl;
}


void		Character::dropMateria(AMateria &materia)
{
	if ((this->_floorCapacity  <= this->_floorIdx))
	{
		this->_floorCapacity += 1;

		//std::cout << "Floor Capacity is " << std::endl;
		//std::cout << this->_floorCapacity << std::endl;
		
		AMateria** newFloor = new AMateria*[this->_floorCapacity];
		for (unsigned int i = 0; i < this->_floorCapacity - 1; i++)
			newFloor[i] = this->_floor[i];
		delete [] this->_floor;

	
		
		AMateria** auxFloor = new AMateria*[this->_floorCapacity];

		this->_floor = auxFloor;	
		for (unsigned int i = 0; i < this->_floorCapacity - 1; i++)
		{
			this->_floor[i] = newFloor[i];			
		}	 
		
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

void Character::unequip(int idx)
{
	std::string name = this->getName();

	if (idx > 3 || idx < 0)
	{
		std::cout << "Unequip err: introduce a valid idx between 0-3." << std::endl;
		return ;
	}
	if (this->_inventory[idx] == NULL)
		std::cout << "Unequip err: there's no weapon in slot: " << idx << " for character " << this->getName() <<std::endl;
	std::cout << "Character " << name << " unequiped " << idx << std::endl;
	this->dropMateria(*_inventory[idx]);
	this->_inventory[idx] = NULL;
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
			std::cout << "Character " << this->getName() << " has equippedt " << this->_inventory[i]->getType() << " in slot  " <<i  << std::endl;
		else
			std::cout << "Character " << this->getName() << " has no equipment in slot " << i << std::endl;
	}
}

void		Character::clearFloor()
{
	for (unsigned int i = 0; i < this->_floorCapacity; i++)
		if (this->_floor[i] != NULL)
		{
			delete this->_floor[i];
			this->_floor[i] = NULL;
		}
}
