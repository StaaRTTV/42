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

NAME	= libftprintf.a
SRCS	= ft_printf.c\
    ft_print_char.c\
    ft_print_hex.c\
    ft_print_nbr.c\
    ft_print_pointer.c\
    ft_print_string.c\
    ft_print_unbr.c

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
