// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Character.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/15 16:50:01 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/17 22:38:07 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

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

	void               listMaterias() const;
	unsigned int       getFloorCapacity() const;
	unsigned int       getFloorIdx() const;

private:

	std::string     _name;
	int             _idx;
    AMateria		*_inventory[4];
	AMateria		**_floor;
	unsigned int	_floorCapacity;
	unsigned int	_floorIdx;
	void		    dropMateria(AMateria &m);
	void	    	clearFloor();	

};
