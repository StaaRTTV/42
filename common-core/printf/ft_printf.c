/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:29:53 by gpochon           #+#    #+#             */
/*   Updated: 2024/11/04 15:41:23 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

static int	ft_percent_what(char c, va_list args)
{
	int		len;

	len = 0;
	if (c == 'c')
	{
		ft_printchar(va_arg(args, int));
		len++;
	}
	else if (c == 's')
		len += ft_printstring(args);
	else if (c == 'u')
		len += ft_printunbr(args);
	else if (c == 'd' || c == 'i')
		len += ft_printnbr(args);
	else if (c == 'p')
		len += ft_print_pointer(args);
	else if (c == 'x' || c == 'X')
		len += ft_print_hex(args, c);
	else if (c == '%')
	{
		ft_printchar('%');
		len++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	va_start(args, format);
	len = 0;
	if (!format)
		return (0);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			len += ft_percent_what(*format, args);
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
/*
int	main()
{
	void	*c = "e";
	ft_printf("test %p %%", c);
	return (0);
}
*/
