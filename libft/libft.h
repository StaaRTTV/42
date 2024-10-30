/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:55:27 by gpochon           #+#    #+#             */
/*   Updated: 2024/10/21 14:03:52 by gpochon          ###   ########.fr       */
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

int		ft_atoi(const char *str);
int		ft_isalnum(int i);
int		ft_isalpha(int i);
int		ft_isascii(int i);
int		ft_isprint(int i);
int		ft_isdigit(int i);
int		ft_strlcat(char *dest, const char *src, size_t size);
int		ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_itoa(int n);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(char *s);
char	*ft_strrchr(const char *str, int i);
char	**ft_split(char const *str, char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	*ft_bzero(void *ptr, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t len);
void	*ft_memmove(void *dest, const void *src, size_t count);
void	*ft_memset(void *ptr, int value, size_t len);
void	*ft_memchr(const void *ptr, int ch, size_t count);
void	*ft_calloc(size_t n, size_t size);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);

#endif
