/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:29:53 by gpochon           #+#    #+#             */
/*   Updated: 2024/11/04 11:37:51 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void	ft_printchar(char c)
{
	write(1, &c, 1);
}

int	ft_printstring(va_list args)
{
	char	*str;
	int	len;

	len = 0;
	str = va_arg(args, char *);
	if (!str)
		return (0);
	while (*str)
	{
		write(1, str, 1);
		str++;
		len++;
	}
	return (len);
}
int	ft_nbr_rec(int nb)
{
	int	len;
	
	len = 0;
	if (nb >= 10)
	{
		len += ft_nbr_rec(nb / 10);
	}
	ft_printchar((nb % 10) + '0'); 
	len++;
	return (len);
}
int	ft_printnbr(va_list args)
{
	int	len;
	int	nb;
	
	nb = va_arg(args, int);
	len = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		len = 11;
		return (len) ;
	}
	if (nb < 0)
	{
		ft_printchar('-');
		nb = -nb;
		len++;
	}
	len += ft_nbr_rec(nb);
	return (len);
}

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
	else if (c == 'p')
		len += ft_print_pointer;
	else if (c == 'd' || c == 'i')
		len += ft_printnbr(args);
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

int	main(void)
{
	int	c = 9;
	ft_printf("test %i %%", c);
	return (0);
}
