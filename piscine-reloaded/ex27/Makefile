# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpochon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 16:52:54 by gpochon           #+#    #+#              #
#    Updated: 2024/10/18 10:12:16 by gpochon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_display_file
SRCS	= ft_display_file.c 
OBJECTS	= $(SRCS:.c=.o)
INCS	= includes
RM	= rm -rf
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

all:	${NAME}

${NAME}: ${OBJECTS}

$clean :
			rm -f ${OBJECTS}

fclean :	clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
