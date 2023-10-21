// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Character.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/15 17:02:27 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/21 22:38:28 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Character.hpp"

Character::Character(void) : _name("anonymous"), _inventoryIdx(0)
{
	std::cout << "Character default constructor called" << std::endl;

	for (unsigned int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;	
	this->_floor = NULL;
	this->_floorIdx = 0;
	return;
}

Character::Character(std::string name) : _name(name), _inventoryIdx(0)
{
	std::cout << "Character name constructor called for "<< this->getName() << std::endl;

	for (unsigned int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	this->_floor = NULL;
	this->_floorIdx = 0;
	return;
}

Character::Character(const Character& inst)
{
	std::cout << "Character copy constructor called" << std::endl;

	//Copy invenntory
	for (unsigned int i = 0; i < 4; i++) {
		if (inst._inventory[ i ] != NULL)
			this->_inventory[ i ] = inst._inventory[ i ]->clone();
		else
			this->_inventory[ i ] = NULL;
	}
	if (inst._floor == NULL)
		this->_floor = NULL;
	else
		this->_floor = copyFloor(inst._floor, inst._floorIdx);
	this->_inventoryIdx = inst._inventoryIdx;
	this->_floorIdx = inst._floorIdx;
	
	return ;
}
	

Character& Character::operator=(const Character& inst)
{

	std::cout << "Character assigment operator called" << std::endl;

	if (this != &inst)
	{
		// Delete inventory
		for ( int i = 0; i < 4; i++ ) {
			if (this->_inventory[i] != NULL)
			{
				delete this->_inventory[ i ];
				this->_inventory[i] = NULL;
			}
		}

		//Copy inventory
		for (unsigned int i = 0; i < 4; i++) {
			if (inst._inventory[ i ] != NULL)
				this->_inventory[ i ] = inst._inventory[ i ]->clone();
			else
				this->_inventory[ i ] = NULL;
		}

		//Delete Floor

		if (this->_floor)
		{
			for (unsigned int i = 0; i < this->_floorIdx; i++)
				delete this->_floor[i];
			delete [] this->_floor;
			this->_floor = NULL;
		}

		this->_floor = copyFloor(inst._floor, inst._floorIdx);
		this->_inventoryIdx = inst._inventoryIdx;
		this->_floorIdx = inst._floorIdx;
	
	}	

	return (*this);
}

Character::~Character(void)
{
	std::cout << "Character default destructor called for " << this->getName() << std::endl;


	//Delete inventory

	for ( unsigned int i = 0; i < 4; i++ ) {
		if (this->_inventory[i] != NULL)
		{
			delete this->_inventory[ i ];
			this->_inventory[i] = NULL;
		}
	}

	//Delete Floor

	if (this->_floor)
	{
		for (unsigned int i = 0; i < this->_floorIdx; i++)
			delete this->_floor[i];
		delete [] this->_floor;
		this->_floor = NULL;
	}	

	return ;
}



std::string const & Character::getName(void) const
{
	return (this->_name);
}



void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || this->_inventory[ idx ] == NULL)
	{
		std::cout << "Cannot use that materia!" << std::endl;
		return ;
	}
	this->_inventory[ idx ]->use(target);
}





void Character::equip(AMateria* m)
{
	static unsigned int has_space = 1;

	if (m == NULL)
	{
		std::cout << "Can not equip an unknown materia" << std::endl;
		return ;
	}
	if (existMateriaInInventory( *m ))
		return ;
	if (existMateriaInFloor( *m ))	
		return ;
	if (!has_space)
	{
		std::cout << "No space left in the inventory, threwing the materia to the floor" << std::endl;
		addFloor( *m );
		return ;
	}
	addInventory( *m );
	std::cout << "Character: " << this->_name << " equip called with materia = " << m->getType() << std::endl;
	if ( this->_inventoryIdx == 4 - 1 && this->_inventory[ this->_inventoryIdx ] != NULL )
		has_space = 0;
		
		
		
}


void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || this->_inventory[ idx ] == NULL)
	{
		std::cout << "Can not unequip an unequiped or inexistent materia" << std::endl;
		return ;
	}
	std::cout << std::endl << "Character: " << this->_name << " just threwn " \
		<< this->_inventory[ idx ]->getType() << " to the floor " << std::endl << std::endl;
	addFloor( *this->_inventory[ idx ] );
	this->_inventory[ idx ] = NULL;
}




void	Character::printFloor( void ) const {
	if (!this->_floor)
	{
		std::cout << "Floor empty" << std::endl;
		return ;
	}
	for (unsigned int i = 0; i < this->_floorIdx; i++)
		if (this->_floor[i])
			std::cout << "The position " << i << " of the floor contains: " << this->_floor[i] << std::endl;
}

void	Character::printMaterias( void ) const {
	for (unsigned int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			std::cout << "The position " << i << " of the INV contains: " << this->_inventory[i] << std::endl;
	}
}




bool	Character::existMateriaInInventory( AMateria& m )
{
	for ( unsigned int i = 0; i < 4; i++ )
	{
		if ( this->_inventory[ i ] == &m )
		{
			std::cout << "This materia has been equiped before" << std::endl;
			return (true);
		}
	}
	return (false);
}


bool	Character::existMateriaInFloor( AMateria& m )
{
	if (this->_floor != NULL)
	{
		for ( unsigned int i = 0; i < this->_floorIdx; i++ )
			if ( this->_floor[ i ] == &m )
			{
				std::cout << "This materia has been thrown before" << std::endl;
				return (true);
			}
	}
	return (false);
}





void	Character::addFloor( AMateria &m ) {
	
	this->_floor = incrementFloorMem( this->_floor, this->_floorIdx );
	this->_floor[this->_floorIdx] = &m;
	this->_floorIdx++;
}

void	Character::addInventory( AMateria& m) {
	while ( this->_inventoryIdx < 4 )
	{
		if ( this->_inventory[ this->_inventoryIdx ] == NULL )
		{
			this->_inventory[ this->_inventoryIdx ] = &m;
			break ;
		}
		this->_inventoryIdx++;
	}
	return ;
}

AMateria **incrementFloorMem( AMateria **floor, unsigned int floorLen )
{
	AMateria **aux = NULL;

	if (floor == NULL)
		return (new AMateria*[1]);
	aux = new AMateria*[floorLen + 1];
	for (unsigned int i = 0; i < floorLen; i++)
		aux[i] = floor[i];
	delete [] floor;
	return (aux);

}





AMateria	**copyFloor( AMateria **srcFloor, unsigned int newFloorLen )
{
	AMateria	**newFloor;

	if (!srcFloor)
		return (NULL);
	newFloor = new AMateria*[newFloorLen];
	for (unsigned int i = 0; i < newFloorLen; i++)
	{
		if (srcFloor[i] != NULL)
			newFloor[i] = srcFloor[i]->clone();
		else
			newFloor[i] = NULL;
	}
	return (newFloor);
}
