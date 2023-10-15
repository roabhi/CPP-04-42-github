// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/15 16:29:13 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/15 20:09:44 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "./classes/character/Character.hpp"
#include "./classes/materia/Ice.hpp"


int main(void)
{
	const Character *Pepe = new Character("Pepe");
	const Character *Anon = new Character();

	const Ice *hielo = new Ice();

    (void) hielo;


	delete Pepe;
	delete Anon;

	return (0);
}
