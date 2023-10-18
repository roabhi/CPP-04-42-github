// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/15 16:29:13 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/18 20:22:46 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "./classes/character/Character.hpp"
#include "./classes/materia/Ice.hpp"
#include "./classes/materia/Cure.hpp"


int main(void)
{

	Character *Pepe = new Character("Pepe");
	Character *Anon = new Character();

	Ice *hielo = new Ice();
	Ice *hielo2 = new Ice();
	Ice *hielo3 = new Ice();
	Ice *hielo4 = new Ice();
	Ice *hielo5 = new Ice();

	Cure *cura = new Cure();
	//Cure *cura2 = new Cure();
	//Cure *cura3 = new Cure();
//	Cure *cura4 = new Cure();
//	Cure *cura5 = new Cure();

	Cure *cura6 = cura;


	Pepe->equip(hielo);
	Anon->equip(hielo);

	Pepe->equip(hielo2);
	Pepe->equip(hielo3);
	Pepe->equip(hielo4);
	Pepe->equip(hielo5);

	Pepe->use(0,*Anon);
	Pepe->use(0,*Anon);

	Pepe->unequip(0);
	Pepe->unequip(2);
	Pepe->unequip(3);
	Pepe->unequip(1);

	std::cout << "Trying to use unequipped" << std::endl;
	
	Pepe->use(1,*Anon);

	Pepe->listMaterias();

	Pepe->equip(hielo5);
	Pepe->equip(hielo);
	Pepe->equip(cura6);
	Pepe->use(3,*Anon);
	
	Pepe->equip(hielo);
	Pepe->equip(cura6);
	Pepe->use(3,*Anon);

	Pepe->unequip(0);
	Pepe->unequip(2);
	Pepe->unequip(3);
	Pepe->unequip(1);
	
	Pepe->equip(hielo);
	Pepe->equip(cura6);
	Pepe->use(3,*Anon);
	

	//Pepe->equip(hielo);
//	Pepe->equip(hielo);


	delete Pepe;
	delete Anon;

	return (0);
}
