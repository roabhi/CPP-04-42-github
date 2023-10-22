#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 16:26:40 by rabril-h          #+#    #+#              #
#    Updated: 2023/10/21 22:53:24 by rabril-h         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = Interface

SRCS = main.cpp \
			./classes/character/Character.cpp \
			./classes/materia/AMateria.cpp \
			./classes/materia/MateriaSource.cpp \
			./classes/materia/Ice.cpp \
			./classes/materia/Cure.cpp \



HEADERS = ./classes/character/ICharacter.hpp \
			./classes/character/Character.hpp \
			./classes/materia/IMateriaSource.hpp \
			./classes/materia/MateriaSource.hpp \
			./classes/materia/AMateria.hpp \
			./classes/materia/Ice.hpp \
			./classes/materia/Cure.hpp \


CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

%.o: %.cpp Makefile ${HEADERS}
		@${CC} ${CFLAGS} -c $< -o $@

OBJS = ${SRCS:.cpp=.o}

${NAME}:: ${OBJS}
	${CC} $(CFLAGS) $(OBJS) -o ${NAME}
	@echo "All files compiled"

all:
		@$(MAKE) ${NAME} 

clean:
			@${RM} ${OBJS} ${DEPS}
			@echo "Objects cleaned"

fclean: clean 
			@${RM} ${OBJS} ${DEPS} ${NAME}
			@echo "All compilation files removed"

re: 
			@$(MAKE) fclean 
			@$(MAKE) all 

.PHONY: all clean fclean re
