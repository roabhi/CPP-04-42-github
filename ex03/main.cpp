// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/15 16:29:13 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/17 21:33:21 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "./classes/character/Character.hpp"
#include "./classes/materia/Ice.hpp"


int main(void)
{
	Character *Pepe = new Character("Pepe");
	Character *Anon = new Character();

	Ice *hielo = new Ice();

	Pepe->equip(hielo);
	Anon->equip(hielo);


	delete Pepe;
	delete Anon;

	return (0);
}
