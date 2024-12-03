# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 13:21:22 by gpochon           #+#    #+#              #
#    Updated: 2024/12/03 14:26:18 by gpochon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
SRCS	= game.c\
    	map.c\
		so_long.c

OBJECTS	= $(SRCS:.c=.o)
INCS	= includes
LIBFT_DIR = ./includes/libft
LIBFT = ${LIBFT_DIR}/libft.a
MLX_DIR = ./minilibx-linux
MLX = ${MLX_DIR}/libmlx.a
COMP	= cc
CFLAGS = -Wall -Wextra -Ofast -march=native -ffast-math -flto
GFLAGS = -g3 -O0 -fsanitize=address
LDFLAGS = -L${LIBFT_DIR} -L$(MLX_DIR) -lft -lmlx -lX11 -lXext -lXrender -lm 

.c.o:
	${COMP} ${CFLAGS} -c $< -o $@

all : ${NAME}

${LIBFT}: 
	make -C ${LIBFT_DIR}

${MLX}:
	make -C ${MLX_DIR}

${NAME}: ${OBJECTS} ${LIBFT} ${MLX}
	${COMP} ${CFLAGS} -o $@ $^ ${LDFLAGS}

debug:
	${MAKE} fclean
	${MAKE} -C ${LIBFT_DIR} fclean
	${MAKE} -C ${LIBFT_DIR} debug
	${MAKE} -C ${MLX_DIR} clean
	${MAKE} -C ${MLX_DIR} debug
	${MAKE} all CFLAGS="${GFLAGS}"

clean :
			rm -f ${OBJECTS}
			make -C ${LIBFT_DIR} clean
			make -C ${MLX_DIR} clean

fclean :	clean
			rm -f ${NAME}
			make -C ${LIBFT_DIR} fclean
			make -C ${MLX_DIR} clean

re:			fclean all

.PHONY:		all clean fclean re