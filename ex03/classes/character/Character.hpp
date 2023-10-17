// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Character.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/15 16:50:01 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/17 21:14:56 by rabril-h         ###   ########.fr       //
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
	//void               unequip(int idx);
	void               use(int idx, ICharacter& target);

private:

	std::string     _name;
	int             _idx;
    AMateria		*_inventory[4];

};
