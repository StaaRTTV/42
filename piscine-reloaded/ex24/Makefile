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

NAME	= libft.a
SRCS	= srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c \
		srcs/ft_swap.c
OBJECTS	= $(SRCS:.c=.o)
AR	= ar rc
LIBR	= ranlib
INCS	= includes
RM	= rm -rf
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

all:	${NAME}

${NAME}:	${OBJECTS}
			${AR} ${NAME} ${OBJECTS}
			${LIBR} ${NAME}
clean :
			rm -f ${OBJECTS}

fclean :	clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
