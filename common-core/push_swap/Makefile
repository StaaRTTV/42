# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 13:21:22 by gpochon           #+#    #+#              #
#    Updated: 2025/01/03 15:53:29 by gpochon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
SRCS	= src/main.c\
		src/multiple_args.c\
		src/single_arg.c
OBJECTS	= $(SRCS:.c=.o)
INCS	= includes
LIBFT_DIR = ./includes/libft
LIBFT = ${LIBFT_DIR}/libft.a
COMP	= cc
CFLAGS = -Wall -Wextra -Ofast -march=native -ffast-math -flto
GFLAGS = -g -O0 -fsanitize=address
LDFLAGS = -L${LIBFT_DIR} -lft 

.c.o:
	${COMP} ${CFLAGS} -c $< -o $@

all : ${NAME}

${LIBFT}: 
	make -C ${LIBFT_DIR}

${NAME}: ${OBJECTS} ${LIBFT}
	${COMP} ${CFLAGS} -o $@ $^ ${LDFLAGS}

debug:
	${MAKE} fclean
	${MAKE} -C ${LIBFT_DIR} fclean
	${MAKE} -C ${LIBFT_DIR} debug
	${MAKE} all CFLAGS="${GFLAGS}"

clean :
	rm -f ${OBJECTS}
	make -C ${LIBFT_DIR} clean

fclean :	clean
	rm -f ${NAME}
	make -C ${LIBFT_DIR} fclean

re:		fclean all

.PHONY:		all clean fclean re
