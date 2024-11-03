/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:29:53 by gpochon           #+#    #+#             */
/*   Updated: 2024/11/03 19:15:33 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_percent_what(char c, va_list args)
{
	if (c == 'c')
		ft_printchar(c);
	else if (c == 's')
		ft_printstring(c);
	else if (c == 'p')
		ft_printchar(c); // a changer
	else if (c == 'd' || c == 'i')
		ft_printnbr(c); 
	else if (c == 'u')
		ft_printnbr(c); // fonction a creer 
	else if (c == 'x')
		ft_printchar(c); // a changer
	else if (c == 'X')
		ft_printchar(c); // a changer
	else if (c == '%')
		ft_printchar('%');
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list args;
	va_start(args, format);

	len = 0;
	if (!format)
		return (0);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			len++;
			format++;
			ft_percent_what(*format, args);
		}
		else
		{
			ft_printchar(*format);
			len++;
		}
		format++;
	}
	va_end(args);
	return (len);
}
