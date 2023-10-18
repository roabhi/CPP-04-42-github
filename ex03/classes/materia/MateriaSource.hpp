// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MateriaSource.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/18 20:34:46 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/18 21:26:56 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

public:
	
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource &inst);
	MateriaSource &operator=(const MateriaSource& inst);

	void      learnMateria(AMateria* m);
	AMateria* createMateria(std::string const & type);
	void      printMaterias() const;

private:

	AMateria  *materias[4];

};

#endif 
