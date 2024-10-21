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

#ifdef LIBFT_H
# define LIBFT_H

int		ft_atoi(const char *str);
int		ft_isalnum(int i);
int		ft_isalpha(int i);
int		ft_isascii(int i);
int		ft_isdigit(int i);
int		ft_isdigit(int i);
int		ft_strlcat(char *dest, const char *src, size_t size);
int		ft_strlcpy(char *dest, char *src, size_t size);
int		ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strrchr(const char *str, int i);
void	ft_bzero(void *ptr, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t len);
void	*ft_memmove(void *dest, const void *src, size_t count);
void	*ft_memset(void *ptr, int value, size_t len);

#endif
