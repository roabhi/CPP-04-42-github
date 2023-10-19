// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/15 16:29:13 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/19 21:48:36 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "./classes/character/Character.hpp"
#include "./classes/materia/Ice.hpp"
#include "./classes/materia/Cure.hpp"
#include "./classes/materia/MateriaSource.hpp"


int main(void)
{

	{

	std::cout << "+++++++++++++++++++++++" << std::endl;
	std::cout << "+++++++++++++++++++++++" << std::endl << std::endl;
	std::cout << std::endl << "First Block of testing" << std::endl << std::endl;
	std::cout << "+++++++++++++++++++++++" << std::endl;
	std::cout << "+++++++++++++++++++++++" << std::endl << std::endl;
		
	Character *Pepe = new Character("Pepe");
	Character *Anon = new Character();

	Ice *hielo = new Ice();
	Ice *hielo2 = new Ice();
	Ice *hielo3 = new Ice();
	Ice *hielo4 = new Ice();
	Ice *hielo5 = new Ice();

	Cure *cura = new Cure();
	Cure *cura6 = cura;


	Pepe->equip(hielo);
	Pepe->equip(hielo2);
	Pepe->equip(hielo3);
	Pepe->equip(hielo4);
	Pepe->equip(hielo5);

	Pepe->use(0,*Anon);
	Pepe->use(1,*Anon);

	Pepe->unequip(0);
	Pepe->unequip(2);
	Pepe->unequip(3);
	Pepe->unequip(1);

	std::cout << "+++++++++++++++++++++++" << std::endl;
	std::cout << "Trying to use unequipped" << std::endl;
	std::cout << "+++++++++++++++++++++++" << std::endl;
	
	Pepe->use(1,*Anon);

	std::cout << "+++++++++++++++++++++++" << std::endl;
	std::cout << "List Materias" << std::endl;
	std::cout << "+++++++++++++++++++++++" << std::endl;

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
	Pepe->unequip(4);
	Pepe->unequip(1);
	
	Pepe->equip(hielo);
	Pepe->equip(cura6);
	Pepe->use(3,*Anon);
	

	Pepe->equip(hielo);
    Pepe->equip(hielo);


	delete Pepe;
	delete Anon;
	delete hielo;
	delete hielo2;
	delete hielo3;
	delete hielo4;
	delete hielo5;
	//delete cura6;
	delete cura;
	

	}

	//{

//	std::cout << "+++++++++++++++++++++++" << std::endl;
//	std::cout << "+++++++++++++++++++++++" << std::endl << std::endl;	
//	std::cout << std::endl << "Second Block of testing" << std::endl << std::endl;
//	std::cout << "+++++++++++++++++++++++" << std::endl;
//	std::cout << "+++++++++++++++++++++++" << std::endl << std::endl;

//	Ice* ice = new Ice();
//	AMateria *cl = ice->clone();
//	AMateria *cure = new Cure(); 	Character *char1 = new Character("Faemino");
// 	Character *char2 = new Character("Cansado");
	
// 	char1->equip(cl);
//	char1->equip(cl);
// 	char1->equip(cure);
// 	char1->equip(cl);
// 	char1->unequip(3);
// 	char1->unequip(2);
// 	char1->equip(cl);
// 	char1->unequip(1);
// 	char1->equip(cure);
// 	char1->unequip(0);
// 	char1->equip(ice);
// 	char1->equip(cl);
// 	char1->use(1, *char2);
// 	char1->use(3, *char2);

//	delete ice;
	//delete cl;
//	delete cure;
// 	delete char1;
// 	delete char2;
		
//	}


	
//	{

//	std::cout << "+++++++++++++++++++++++" << std::endl;
//	std::cout << "+++++++++++++++++++++++" << std::endl << std::endl;
//	std::cout << std::endl << "Third Block of testing" << std::endl << std::endl;
//	std::cout << "+++++++++++++++++++++++" << std::endl;
//	std::cout << "+++++++++++++++++++++++" << std::endl << std::endl;
		
//	IMateriaSource* materiaSrc = new MateriaSource();
//	materiaSrc->learnMateria(new Ice());
//	materiaSrc->learnMateria(new Cure());
	
//	ICharacter* char1 = new Character("Faemino");
//	AMateria* tmp;
//	tmp = materiaSrc->createMateria("ice");
//	char1->equip(tmp);
//	tmp = materiaSrc->createMateria("cure");
//	char1->equip(tmp);
//	ICharacter* char2 = new Character("Cansado");
//	char1->use(0, *char2);
//	char1->use(1, *char2);
	
//	delete char2;
//	delete char1;
//	delete materiaSrc;
//	delete tmp;

//	}


//	{

//		std::cout << "+++++++++++++++++++++++" << std::endl;
//	std::cout << "+++++++++++++++++++++++" << std::endl << std::endl;
//	std::cout << std::endl << "Forth Block of testing" << std::endl << std::endl;
//	std::cout << "+++++++++++++++++++++++" << std::endl;
//	std::cout << "+++++++++++++++++++++++" << std::endl << std::endl;


//		std::cout << "1. Creating MateriaSource" << std::endl; 
//		IMateriaSource* src = new MateriaSource();
//		std::cout << std::endl;
//		src->printMaterias();
//	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

//	std::cout << "2. \"src\" learning 5 materias" << std::endl << std::endl;
//		src->learnMateria(new Ice());
//		src->learnMateria(new Cure());
//		src->learnMateria(new Ice());
//		src->learnMateria(new Cure());
		
//		std::cout << std::endl;
//		Ice	*mat = new Ice();
//		src->learnMateria(mat);
//		delete	mat;

		// std::cout << std::endl;
//		src->printMaterias();
//	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

//	std::cout << "3. Creating Character \"vilma\" and \"oktorok\"" << std::endl << std::endl;
//		Character* vilma = new Character("vilma");
//		vilma->listMaterias();
//		std::cout << std::endl;

//		Character* oktorok = new Character("oktorok");
//		oktorok->listMaterias();
//	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

//	std::cout << "4. \"vilma\" trying to equip 5 materias and \"oktorok\" one materia" << std::endl << std::endl;
//		vilma->equip(NULL);
		
//		AMateria* tmp;

//		tmp = src->createMateria("ice");
//		vilma->equip(tmp);
//		tmp = src->createMateria("ice");
//		vilma->equip(tmp);


//		tmp = src->createMateria("cure");
//		vilma->equip(tmp);
//		tmp = src->createMateria("cure");
//		vilma->equip(tmp);
//		tmp = src->createMateria("ice");
//		vilma->equip(tmp);

//		std::cout << std::endl;
//		vilma->listMaterias();

//		std::cout << std::endl;
//		tmp = src->createMateria("ice"); //esto lo pongo yo
//		oktorok->equip(tmp);
//	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

//	std::cout << "5. Testing Character Assignation overload \"vilma = oktorok\" for deep copy and changed vilma afterwards" << std::endl << std::endl;
//		*oktorok = *vilma;
		
//		vilma->unequip(0);
//		std::cout << "VILMA" << std::endl;
//		vilma->listMaterias();
//		std::cout << std::endl;

//		std::cout << "OKTOROK" << std::endl;
//		oktorok->listMaterias();
//	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

//	std::cout << "6. Testing character copy constructor for deep copy \"stardust = Character(vilma)\" and changed vilma afterwards" << std::endl << std::endl;
		
//		vilma->listMaterias();
//		Character* stardust = new Character(*vilma);
//		stardust->listMaterias();

//		tmp = src->createMateria("ice");
//		vilma->equip(tmp);
//		std::cout << "VILMA" << std::endl;
//		vilma->listMaterias();
//		std::cout << std::endl;

//		std::cout << "STARDUST" << std::endl;
//		stardust->listMaterias();


//	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //
	
//	std::cout << "7. \"vilma\" using all equiped materias on \"oktorok\" " << std::endl << std::endl;
//		vilma->use(0, *oktorok);
//		vilma->use(1, *oktorok);
//		vilma->use(2, *oktorok);
//		vilma->use(3, *oktorok);
//		vilma->use(10, *oktorok);
//		vilma->use(-1, *oktorok);
//	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

//	std::cout << "8. \"vilma\" trying to use unequiped materias on \"oktorok\" " << std::endl << std::endl;
//		vilma->unequip(0);
//		vilma->use(0, *oktorok);

//	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

//	std::cout << "9. New character \"lucifer\" equipping and unequipping materias" << std::endl << std::endl;
//		ICharacter* lucifer = new Character("lucifer");
//		AMateria *cure = new Cure;
//		AMateria *ice = new Ice;

//		lucifer->equip(cure);
//		lucifer->equip(ice);
//		lucifer->equip(cure);
//		lucifer->equip(ice);
//		lucifer->unequip(0);
//		lucifer->unequip(1);
//		lucifer->unequip(2);
//		lucifer->unequip(3);
//		lucifer->equip(cure);
//		lucifer->equip(ice);

		//lucifer->printMaterias();
		// lucifer->printTrash();

//	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

//	std::cout << "10. Testing if unequiped materia is freed" << std::endl << std::endl;

//		ICharacter* test = new Character("test");
		
//		tmp = src->createMateria("ice");
//		test->equip(tmp);
//		test->unequip(0);

//	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //
//	std::cout << "11. Deleting \"vilma\", \"oktorok\", \"stardust\" and \"lucifer\"" << std::endl << std::endl;
	
//	delete test;
//	delete lucifer;
//	delete stardust;
//	delete oktorok;
//	delete vilma;
//	delete src;

		
//	}

	return (0);
}
