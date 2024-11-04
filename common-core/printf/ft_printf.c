/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:29:53 by gpochon           #+#    #+#             */
/*   Updated: 2024/11/04 14:58:54 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

static int	ft_percent_what(char c, va_list args)
{
	int	len;
	
	len = 0;
	if (c == 'c')
	{
		char ch = va_arg(args, int);
		ft_printchar(ch);
		len++;
	}
	else if (c == 's')
		len += ft_printstring(args);
	else if (c == 'u')
		len += ft_printunbr(args);
	else if (c == 'd' || c == 'i')
		len += ft_printnbr(args);
	else if (c == 'p')
		ft_print_pointer(args);
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
	va_list args;
	va_start(args, format);

	len = 0;
	if (!format)
		return (0);
	while (*format != '\0')
	{
		if (*format == '%')
		{	
			format++;
			if (*format == '\0')
				return (0);
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
/*int	main()
{
	void	*c = "e";
	ft_printf("test %p %%", c);
	return (0);
}*/
