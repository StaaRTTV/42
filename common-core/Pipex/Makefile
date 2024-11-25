# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 14:02:20 by gpochon           #+#    #+#              #
#    Updated: 2024/11/05 14:02:24 by gpochon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
SRCS	= error_handler.c\
    ft_child.c\
    pipex.c\
    pipex_tools.c\

OBJECTS	= $(SRCS:.c=.o)
INCS	= includes
COMP	= cc
CFLAGS	= -Wall -Wextra -Werror
AR = ar crs

.c.o:
	${COMP} ${CFLAGS} -c $< -o $@

all:	${NAME}

${NAME}: ${OBJECTS}
	$(AR) $@ $^

clean :
			rm -f ${OBJECTS}

fclean :	clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
