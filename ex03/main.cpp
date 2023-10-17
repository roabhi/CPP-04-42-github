// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/15 16:29:13 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/17 23:32:41 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "./classes/character/Character.hpp"
#include "./classes/materia/Ice.hpp"


int main(void)
{
	Character *Pepe = new Character("Pepe");
	Character *Anon = new Character();

	Ice *hielo = new Ice();
	Ice *hielo2 = new Ice();
	Ice *hielo3 = new Ice();
	Ice *hielo4 = new Ice();
	//Ice *hielo5 = new Ice();

	Pepe->equip(hielo);
	Anon->equip(hielo);

	Pepe->equip(hielo2);
	Pepe->equip(hielo3);
	Pepe->equip(hielo4);
	//Pepe->equip(hielo5);

	Pepe->listMaterias();


	delete Pepe;
	delete Anon;

	return (0);
}
