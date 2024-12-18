# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 14:02:20 by gpochon           #+#    #+#              #
#    Updated: 2024/12/18 11:04:29 by gpochon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
SRCS	= error_handler.c\
    ft_child.c\
    pipex.c\
    ft_path.c

OBJECTS	= $(SRCS:.c=.o)
INCS	= includes
LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a
COMP	= gcc
CFLAGS	= -Wall -Wextra -Werror -g -I${INCS} -fPIC
LDFLAGS = -L${LIBFT_DIR} -lft

.c.o:
	${COMP} ${CFLAGS} -c $< -o $@

all : ${NAME}

${LIBFT}: 
	make -C ${LIBFT_DIR}

${NAME}: ${OBJECTS} ${LIBFT}
	${COMP} ${CFLAGS} -o $@ $^ ${LDFLAGS}

clean :
			rm -f ${OBJECTS}
			make -C ${LIBFT_DIR} clean

fclean :	clean
			rm -f ${NAME}
			make -C ${LIBFT_DIR} fclean

re:			fclean all

.PHONY:		all clean fclean re
