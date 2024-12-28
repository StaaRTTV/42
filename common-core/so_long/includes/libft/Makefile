NAME	= libft.a
SRCS	= ft_atoi.c\
	ft_bzero.c\
	ft_calloc.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_itoa.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memset.c\
	ft_split.c\
	ft_strchr.c\
	ft_strdup.c\
	ft_strjoin.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_putnbr_fd.c\
	ft_strlen.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_strncmp.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_tolower.c\
	ft_strtrim.c\
	ft_substr.c\
	ft_toupper.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_strdup.c\
	ft_print_char.c\
	ft_print_hex.c\
	ft_print_nbr.c\
	ft_print_pointer.c\
	ft_print_string.c\
	ft_print_unbr.c\
	ft_printf.c\
	get_next_line.c\
	get_next_line_bonus.c\
	get_next_line_utils.c\
	get_next_line_utils_bonus.c\
	ft_lstnew_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstsize_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstadd_back_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstmap_bonus.c\
	ft_strlen2emedunom.c\

OBJECTS	= $(SRCS:.c=.o)
INCS	= includes
COMP	= cc
CFLAGS = -Wall -Wextra -Werror -Ofast -march=native -ffast-math -flto
GFLAGS = -g3 -O0 -fsanitize=address
AR = llvm-ar-12 rcs
RANLIB = llvm-ranlib-12

.c.o:
	${COMP} ${CFLAGS} -c $< -o $@

all:	${NAME}

${NAME}: ${OBJECTS}
	$(AR) $@ $^
	$(RANLIB) $@

clean :
			rm -f ${OBJECTS}

fclean :	clean
			rm -f ${NAME} 

re:			fclean all

debug: CFLAGS = $(GFLAGS)
debug: fclean ${OBJECTS}
	$(AR) $(NAME) $(OBJECTS)
	$(RANLIB) $(NAME)

.PHONY:		all clean fclean re
