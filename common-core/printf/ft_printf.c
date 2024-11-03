/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:29:53 by gpochon           #+#    #+#             */
/*   Updated: 2024/11/03 16:45:37 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

static void	ft_percent_what(char c)
{
	if (c == 'c')
		ft_putchar(c)
	if (c == 's')
		ft_putstr(c)
	if (c == 'p')
	if (c == 'd' || c == 'i')
		ft_putnbr(c)
	if (c == 'u')
		ft_putuns(c) // fonction a creer 
	if (c == 'x')
	if (c == 'X')
	if (c == '%')
		ft_putchar('%')
}

int	ft_printf(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_percent_what(str[i])
		}
		else
		{
			ft_putchar(str[i])
			i++;
		}
	}
	return ();
}
