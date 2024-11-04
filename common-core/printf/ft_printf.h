/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:22:14 by gpochon           #+#    #+#             */
/*   Updated: 2024/11/04 15:13:48 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_printstring(va_list args);
int		ft_printnbr(va_list args);
int		ft_printunbr(va_list args);
void	ft_printchar(char c);
void	ft_print_pointer(va_list args);

#endif