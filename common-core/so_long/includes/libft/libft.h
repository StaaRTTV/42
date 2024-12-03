/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:55:27 by gpochon           #+#    #+#             */
/*   Updated: 2024/11/21 11:15:55 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <malloc.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdint.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

int				ft_printf(const char *format, ...);
int				ft_print_string(va_list args);
int				ft_print_nbr(va_list args);
int				ft_print_unbr(va_list args);
int				witch_one(unsigned int nb, char c);
int				ft_print_pointer(void *ptr);
int				ft_lstsize(t_list *lst);
int				ft_atoi(const char *str);
int				ft_isalnum(int i);
int				ft_isalpha(int i);
int				ft_isascii(int i);
int				ft_isprint(int i);
int				ft_isdigit(int i);
int				ft_strlcat(char *dest, const char *src, size_t size);
int				ft_strlcpy(char *dest, const char *src, size_t size);
int				ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*get_next_line(int fd);
char			*ft_strchr_gnl(const char *str, int c);
char			*ft_strdup_gnl(char *s);
char			*ft_substr_gnl(char const *s, unsigned int start, size_t len);
char			*ft_strjoin_gnl(char const *s1, char const *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_itoa(int n);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(const char *str, int c);
char			*ft_strdup(char *s);
char			*ft_strrchr(const char *str, int i);
char			**ft_split(char const *str, char c);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_print_char(char c);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			*ft_bzero(void *ptr, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t len);
void			*ft_memmove(void *dest, const void *src, size_t count);
void			*ft_memset(void *ptr, int value, size_t len);
void			*ft_memchr(const void *ptr, int ch, size_t count);
void			*ft_calloc(size_t n, size_t size);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
unsigned int	ft_strlen_gnl(const char *str);
#endif
