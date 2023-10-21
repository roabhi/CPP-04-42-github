// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Character.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/15 16:50:01 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/21 22:17:06 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {

public:

	Character(void);
	~Character(void);
	Character(const Character& inst);
	Character(std::string name);
	Character& operator=(const Character& inst);

	std::string const & getName(void) const;
	
	void               equip(AMateria* m);
    void               unequip(int idx);
	void               use(int idx, ICharacter& target);

	void			   addFloor( AMateria &m );
	void			   addInventory( AMateria &m );
	void			   deleteFloor( void );
	void			   deleteInventory( void );
	void		       printFloor( void ) const;
	void		       printMaterias( void ) const;
	bool			   existMateriaInFloor( AMateria& m );
	bool		       existMateriaInInventory( AMateria& m );

private:

	std::string     _name;
    AMateria		*_inventory[4];
	AMateria		**_floor;
	
	unsigned int	_floorIdx;
	unsigned int    _inventoryIdx;
	


};

AMateria				**incrementFloorMem( AMateria **floor, unsigned int floorLen );
AMateria				**copyFloor( AMateria **srcFloor, unsigned int newFloorLen );

#endif
