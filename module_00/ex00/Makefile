# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/06 11:39:08 by pmachado          #+#    #+#              #
#    Updated: 2025/08/06 11:56:25 by pmachado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-------------VARIABLES-------------#

CXX 			= c++
CXXFLAGS 		= -Wall -Wextra -Werror

#-------------SOURCES-------------#

NAME		= megaphone
SRC			= ${NAME}.cpp
OBJ			= ${SRC:.cpp=.o}

#-------------RULES-------------#

all:		${NAME}
${NAME}:	${OBJ}
		${CXX} ${CXXFLAGS} ${OBJ} -o ${NAME}

clean:
		rm -f ${OBJ}
fclean:	clean
		rm -f ${NAME}
re:		fclean all

.PHONY:	all clean fclean re