/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:35:06 by gpochon           #+#    #+#             */
/*   Updated: 2024/11/05 13:27:27 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_hex(unsigned int nb, char *base)
{
	int i;

	i = 0;
	if (nb >= 16)
		i += ft_print_hex(nb / 16, base);
	ft_print_char(base[nb % 16]);
	i++;
	return (i);
}
int	witch_one(unsigned int nb, char c)
{
	if (c == 'x')
		return (ft_print_hex(nb, "0123456789abcdef"));
	if (c == 'X')
		return (ft_print_hex(nb, "0123456789ABCDEF"));
	return (0);
}
