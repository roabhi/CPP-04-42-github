// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Brain.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/12 17:23:06 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/12 18:51:31 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

class Brain {

public:
	Brain(void);
	Brain(const Brain &inst);
	Brain &operator=(const Brain& inst);
	virtual ~Brain();

	void showIdeas() const;
	void setIdeas(std::string const &ideas);

private:

	std::string _ideas[100];
	unsigned int _idx;


};
