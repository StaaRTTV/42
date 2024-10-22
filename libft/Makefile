NAME	= libft.a
SRCS	= ft_*.c 
OBJECTS	= $(SRCS:.c=.o)
INCS	= includes
RM	= rm -rf
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
AR = ar crs

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

all:	${NAME}

${NAME}: ${OBJECTS}
	$(AR) $@ $^

$clean :
			rm -f ${OBJECTS}

fclean :	clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
