# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 13:21:22 by gpochon           #+#    #+#              #
#    Updated: 2024/12/30 13:18:31 by gpochon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
SRCS	= game.c\
	map.c\
	so_long.c\
	map_validator.c\
	movements.c\
	bonus_bonus.c\
	solglissant_bonus.c\
	map_validator2.c\
	solglissant2_bonus.c\
	dfs.c\
	dfs_e.c\
	free.c

OBJECTS	= $(SRCS:.c=.o)
INCS	= includes
LIBFT_DIR = ./includes/libft
LIBFT = ${LIBFT_DIR}/libft.a
MLX_DIR = ./mlx
MLX = ${MLX_DIR}/libmlx.a
COMP	= cc
CFLAGS = -Wall -Wextra -Ofast -march=native -ffast-math -flto
GFLAGS = -g -O0 -fsanitize=address
LDFLAGS = -L${LIBFT_DIR} -L$(MLX_DIR) -lft -lmlx -lX11 -lXext -lXrender -lm

.c.o:
	@echo "🔥 Compiling: $< 🔥"
	${COMP} ${CFLAGS} -c $< -o $@

all : ${NAME}

${LIBFT}: 
	@echo "🏋️‍♂️ Building Libft like a Chad..."
	make -C ${LIBFT_DIR}

${MLX}:
	@echo "🛠️ Assembling the MiniLibX greatness..."
	make -C ${MLX_DIR}

${NAME}: ${OBJECTS} ${LIBFT} ${MLX}
	@echo "⚡ Linking everything to create ${NAME} ⚡"
	${COMP} ${CFLAGS} -o $@ $^ ${LDFLAGS}
	@echo "🚀 ${NAME} is ready to dominate the universe! 🚀"

bonus:	all
	@echo "🎉 Bonus mode activated! Flex those coding muscles! 🎉"

debug:
	@echo "🐞 Debug mode enabled! Prepare for battle! 🐞"
	${MAKE} fclean
	${MAKE} -C ${LIBFT_DIR} fclean
	${MAKE} -C ${LIBFT_DIR} debug
	${MAKE} -C ${MLX_DIR} clean
	${MAKE} -C ${MLX_DIR} debug
	${MAKE} all CFLAGS="${GFLAGS}"

clean :
	@echo "🧹 Cleaning up the mess..."
	rm -f ${OBJECTS}
	make -C ${LIBFT_DIR} clean
	make -C ${MLX_DIR} clean
	@echo "✅ Cleanup complete. Ready for more action."

fclean :	clean
	@echo "🗑️ Full cleanup initiated. Leaving no traces behind!"
	rm -f ${NAME}
	make -C ${LIBFT_DIR} fclean
	make -C ${MLX_DIR} clean
	@echo "🚮 All clean. Let's build it again!"

re:			fclean all
	@echo "🔄 Rebuilding everything from scratch. Chad style. 🔄"

.PHONY:		all clean fclean re bonus debug

