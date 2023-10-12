#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 17:07:01 by rabril-h          #+#    #+#              #
#    Updated: 2023/10/12 18:53:06 by rabril-h         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME = WorldOnFire

SRCS = main.cpp \
				./classes/animals/Animal.cpp \
				./classes/animals/Dog.cpp \
				./classes/animals/Cat.cpp \
				./classes/Brain.cpp \



HEADERS = ./classes/animals/Animal.hpp \
				./classes/animals/Dog.hpp \
				./classes/animals/Cat.hpp \
				./classes/Brain.hpp \


CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g #-fsanitize=address

%.o: %.cpp Makefile ${HEADERS}
		@${CC} ${CFLAGS} -c $< -o $@

OBJS = ${SRCS:.cpp=.o}
DEPS = ${SRCS:.cpp=.d}

${NAME}:: ${OBJS}
	${CC} $(CFLAGS) $(OBJS) -o ${NAME}
	@echo "All files compiled"

all:
		@$(MAKE) ${NAME} 

-include ${DEPS}

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
